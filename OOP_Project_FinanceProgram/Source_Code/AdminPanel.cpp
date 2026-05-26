// AdminPanel.cpp
#include "AppController.h"
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

// Admin Panel Logic
void AppController::AdminPanel() {
    bool inAdminMenu = true;
    int choice;

    while (inAdminMenu) {
        system("cls");
        cout << "----------ADMIN CONTROL PANEL-----------" << endl;
        cout << "1. View All Registered Users" << endl;
        cout << "2. Delete User Account" << endl;

        // To access admin registration part
        if (currentUser->getEmail() == "admin@gmail.com") {
            cout << "3. Manage System Administrators" << endl;
        }
        cout << "0. Back to Main Menu" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Admin Choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }

        switch (choice) {
        case 1:
            AllUsers(); 
            break;
        case 2:
            deleteUser(); 
            break;
        case 3:
            if (currentUser->getEmail() == "admin@gmail.com") {
                Admins(); 
                break;
            }
            else {
                cout << "\n[Error]: Invalid choice! Please try again." << endl;
                system("pause");
                break;
            }
        case 0:
            inAdminMenu = false; 
            break;
        default:
            cout << "\n[Error]: Invalid choice! Please try again." << endl;
            system("pause");
            break;
        }
    }
}

// listAllCards function
void AppController::AllUsers() {
    system("cls");
    ifstream inFile("users.dat", ios::binary);
    UserBinary temp;

    cout << "--- REGISTERED USERS LIST ---" << endl;
    cout << left << setw(15) << "User" << setw(25) << "Email" << endl;
    cout << "---------------------------------------------"<<endl;

    int totalUsers = 0;

    while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(UserBinary))) {
        cout << left << setw(15) << temp.username << setw(25) << temp.email << endl;
        totalUsers++; // Plus to total user
    }
    cout << "---------------------------------------------" << endl;
    cout << "Total Users: " << totalUsers << endl;
    inFile.close();
    system("pause");
}


// deleteUser function
void AppController::deleteUser() {
    try {
        string targetEmail;
        cout << "Enter Email to DELETE (or '0' to cancel): ";
        cin >> targetEmail;

        if (targetEmail == "0") 
            return;

        if (targetEmail == currentUser->getEmail()) {
            throw "Self-deletion detected";
        }

        // if target is admin, we cannot delete them
        ifstream adminCheck("admins.dat", ios::binary);
        if (adminCheck.is_open()) {
            UserBinary localAdmin;
            while (adminCheck.read(reinterpret_cast<char*>(&localAdmin), sizeof(UserBinary))) {
                if (targetEmail == localAdmin.email) {
                    adminCheck.close();
                    throw "Access Denied: Target is a System Administrator! Wiping an admin directly is forbidden.\nYou must remove their admin privileges from the 'Manage System Administrators' menu first.";
                }
            }
            adminCheck.close();
        }

        // step 1 users.dat
        ifstream inFile("users.dat", ios::binary);
        if (!inFile) 
            throw "Database 'users.dat' not found.";

        vector<UserBinary> remainingUsers; // temperory records
        UserBinary tempUser;
        bool found = false;

        // We read all records and save everyone except the target user
        while (inFile.read(reinterpret_cast<char*>(&tempUser), sizeof(UserBinary))) {
            if (targetEmail != tempUser.email) {
                remainingUsers.push_back(tempUser);
            }
            else {
                found = true; // Target found
            }
        }
        inFile.close();

        if (!found)
            throw "User with this email not found in the database.";

        // We rewrite the file from scratch using
        ofstream outFile("users.dat", ios::binary | ios::trunc);
        if (!outFile) 
            throw "Failed to open 'users.dat' for overwriting.";

        for (int i = 0; i < remainingUsers.size(); i++) {
            outFile.write(reinterpret_cast<char*>(&remainingUsers[i]), sizeof(UserBinary));
        }
        outFile.close();

        // step 2 cards.txt
        ifstream cardIn("cards.txt");
        vector<string> remainingCards;
        string line;

        if (cardIn.is_open()) {
            while (getline(cardIn, line)) {
                // If line does NOT start with target user's email
                if (line.find(targetEmail + ",") != 0 && !line.empty()) {
                    remainingCards.push_back(line);
                }
            }
            cardIn.close();

            // Clear file and restore kept cards
            ofstream cardOut("cards.txt", ios::trunc);
            if (cardOut.is_open()) {
                for (int i = 0; i < remainingCards.size(); i++) {
                    cardOut << remainingCards[i] << endl;
                }
                cardOut.close();
            }
        }

        // step 3 history.txt
        ifstream histIn("history.txt");
        vector<string> remainingHistory;

        if (histIn.is_open()) {
            while (getline(histIn, line)) {
                if (line.find(targetEmail + ",") != 0 && !line.empty()) {
                    remainingHistory.push_back(line);
                }
            }
            histIn.close();

            // Clear file and restore kept history records
            ofstream histOut("history.txt", ios::trunc);
            if (histOut.is_open()) {
                for (int i = 0; i < remainingHistory.size(); i++) {
                    histOut << remainingHistory[i] << endl;
                }
                histOut.close();
            }
        }

        cout << "\n[SUCCESS]: Full deletion of user is complete." << endl;
        cout << "- Binary record deleted.\n- Cards removed.\n- History wiped." << endl;
        system("pause");
    }
    catch (const char* errorMsg) {
        cout << "\n[ADMIN ERROR]: " << errorMsg << endl;
        system("pause");
    }
}

void AppController::Admins() {
    bool inSubMenu = true;
    int choice;

    while (inSubMenu) {
        system("cls");
        ifstream inFile("admins.dat", ios::binary);
        UserBinary temp;

        // First view list of all admins
        cout << "--- SYSTEM ADMINISTRATORS LIST ---" << endl;
        cout << left << setw(15) << "Admin User" << setw(25) << "Email" << endl;
        cout << "---------------------------------------------" << endl;
        cout << left << setw(15) << "System" << setw(25) << "admin@gmail.com" << endl;

        int totalAdmins = 0;
        if (inFile.is_open()) {
            while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(UserBinary))) {
                cout << left << setw(15) << temp.username << setw(25) << temp.email << endl;
                totalAdmins++;
            }
            inFile.close();
        }
        cout << "---------------------------------------------" << endl;
        cout << "Total Admins: " << totalAdmins << endl << endl;

        cout << "1. Add Admin Privileges" << endl;
        cout << "2. Remove Admin Privileges" << endl;
        cout << "0. Back to Admin Panel" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }

        switch (choice) {
        case 1:
            // Call add admin
            try {
                string Email;
                cout << "Enter existing user's Email to give Admin rights: ";
                cin >> Email;

                // Search user.dat to add them in damin
                fstream userFile("users.dat", ios::binary | ios::in | ios::out);
                if (!userFile) 
                    throw "File 'users.dat' not found.";

                UserBinary foundUser;
                bool userExists = false;
                streampos pos;

                while (userFile.read(reinterpret_cast<char*>(&foundUser), sizeof(UserBinary))) {
                    if (Email == foundUser.email) {
                        userExists = true;
                        pos = userFile.tellg() - (streamoff)sizeof(UserBinary); // We save position
                        break;
                    }
                }

                if (!userExists) {
                    userFile.close();
                    throw "User not found! You can only promote existing users.";
                }

                // Check if user is already an admin
                if (foundUser.role == 1) {
                    userFile.close();
                    throw "This user is already an administrator.";
                }

                // Check to prevent the dublication
                ifstream adminCheck("admins.dat", ios::binary);
                if (adminCheck.is_open()) {
                    UserBinary localAdmin;
                    while (adminCheck.read(reinterpret_cast<char*>(&localAdmin), sizeof(UserBinary))) {
                        if (Email == localAdmin.email) {
                            adminCheck.close();
                            userFile.close();
                            throw "Critical Error: Email already exists in admins.dat.";
                        }
                    }
                    adminCheck.close();
                }

                // Change users.dat role to 1
                foundUser.role = 1;
                userFile.seekp(pos);
                userFile.write(reinterpret_cast<char*>(&foundUser), sizeof(UserBinary));
                userFile.close();

                // Add to amins.dat
                ofstream adminOut("admins.dat", ios::binary | ios::app);
                adminOut.write(reinterpret_cast<char*>(&foundUser), sizeof(UserBinary));
                adminOut.close();

                cout << "\n[SUCCESS]: " << foundUser.username << " is now a System Administrator!" << endl;
                system("pause");
            }
            catch (const char* msg) {
                cout << "\n[ERROR]: " << msg << endl;
                system("pause");
            }
            break;

        case 2:
            // Deletion an admin
            try {
                string targetEmail;
                cout << "Enter Admin Email to remove privileges: ";
                cin >> targetEmail;
                
                // Validation checking
                if (targetEmail == currentUser->getEmail()) {
                    throw "Demotion Security: You cannot remove your own admin privileges!";
                }

                ifstream adminIn("admins.dat", ios::binary);
                if (!adminIn) 
                    throw "No administrators database found.";

                vector<UserBinary> remainingAdmins;
                UserBinary tempAdmin;
                bool foundInAdmins = false;

                while (adminIn.read(reinterpret_cast<char*>(&tempAdmin), sizeof(UserBinary))) {
                    if (targetEmail != tempAdmin.email) {
                        remainingAdmins.push_back(tempAdmin);
                    }
                    else {
                        foundInAdmins = true;
                    }
                }
                adminIn.close();

                if (!foundInAdmins) 
                    throw "This email is not in the administrator list.";

                // Rewrite the admins.dat
                ofstream adminOut("admins.dat", ios::binary | ios::trunc);
                for (size_t i = 0; i < remainingAdmins.size(); i++) {
                    adminOut.write(reinterpret_cast<char*>(&remainingAdmins[i]), sizeof(UserBinary));
                }
                adminOut.close();

                // Rewrite the role to zero in users.dat 
                fstream userFile("users.dat", ios::binary | ios::in | ios::out);
                if (userFile.is_open()) {
                    UserBinary u;
                    while (userFile.read(reinterpret_cast<char*>(&u), sizeof(UserBinary))) {
                        if (targetEmail == u.email) {
                            u.role = 0; // here role is zero
                            streampos p = userFile.tellg() - (streamoff)sizeof(UserBinary);
                            userFile.seekp(p);
                            userFile.write(reinterpret_cast<char*>(&u), sizeof(UserBinary));
                            break;
                        }
                    }
                    userFile.close();
                }

                cout << "\n[SUCCESS]: Admin privileges revoked. User downgraded to standard role." << endl;
                system("pause");
            }
            catch (const char* msg) {
                cout << "\n[ERROR]: " << msg << endl;
                system("pause");
            }
            break;

        case 0:
            inSubMenu = false; break;
        }
    }
}