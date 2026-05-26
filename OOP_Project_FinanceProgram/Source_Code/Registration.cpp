// Registration.cpp
#include "AppController.h"
#include <fstream>

// handleSignUp logic for registering a new user to a binary file
void AppController::SignUp() {
    try {
        string email, usern, ps, cardName;
        double initBal;

        cout << "\n--- Registration ---" << endl;

        // Input Email
        cout << "Email: ";
        cin >> email;

        // Input Username
        cout << "Username: ";
        cin >> usern;

        cin.ignore(1000, '\n'); // We should clear buffer before using getline

        // Validateion
        ifstream checkUserFile("users.dat", ios::binary);
        if (checkUserFile.is_open()) {
            UserBinary temp;
            // We use binary file reading method
            while (checkUserFile.read(reinterpret_cast<char*>(&temp), sizeof(UserBinary))) {
                // We check if mail already exists
                if (email == temp.email) {
                    checkUserFile.close();
                    throw "This email is already registered!";
                }
                // We check if username already exists
                if (usern == temp.username) {
                    checkUserFile.close();
                    throw "This username is already taken!";
                }
            }
            checkUserFile.close();
        }

        // We continue with other inputs if user doesn't exist

        cout << "Password: ";
        getline(cin, ps);
        if (ps.empty())
            throw "Password cannot be empty!";

        cout << "First Card Name: ";
        getline(cin, cardName);
        if (cardName.empty())
            throw "Card name cannot be empty!";

        cout << "Initial Balance: ";
        if (!(cin >> initBal)) {
            cin.clear(); // We clear stream error flag
            cin.ignore(1000, '\n');
            throw "Invalid balance! Please enter a number.";
        }
        if (initBal < 0)
            throw "Initial balance cannot be negative!";

        // Save to binary file
        // Use struct UserBinary from file
        UserBinary record;
        // We fill fixed-size char arrays safely.
        email.copy(record.email, 39);
        record.email[email.size() < 39 ? email.size() : 39] = '\0'; // Ensure null-termination at the end
        usern.copy(record.username, 29);
        record.username[usern.size() < 29 ? usern.size() : 29] = '\0';
        ps.copy(record.password, 29);
        record.password[ps.size() < 29 ? ps.size() : 29] = '\0';

        record.role = 0; // 0 standard user, 1 admin

        // Opening users file and save them
        ofstream outFile("users.dat", ios::binary | ios::app);
        if (!outFile)
            throw "Could not open database file!";

        outFile.write(reinterpret_cast<const char*>(&record), sizeof(UserBinary));
        outFile.close();

        // Save card to txt file
        ofstream cardFile("cards.txt", ios::app);
        cardFile << email << "," << cardName << "," << initBal << endl;
        cardFile.close();

        // Log in current user to class User
        currentUser = new User(email, usern, ps, 0);
        Card firstCard;
        firstCard.name = cardName;
        firstCard.balance = initBal;
        userCards.clear(); // We should clear previous user Cards list before loading new one
        userCards.push_back(firstCard); // Add user first card using push_back

        totalTransactions = 0;

        cout << "\n[Success] Account created! Welcome, " << usern << endl;
        system("pause");
    }
    // catch for any error 
    catch (const char* error) {
        cout << "\n[Validation Error]: " << error << endl;
        cin.clear();
        cin.ignore(1000, '\n'); // Cleaning
        system("pause");
    }
}

// handleSignIn function
void AppController::SignIn() {
    system("cls");
    string Email, Password;

    cout << "--- SIGN IN ---" << endl;;
    cout << "[ Enter '0' to go back ]" << endl;;
    cout << "Email: ";
    cin >> Email;

    if (Email == "0")
        return;

    cout << "Password: ";
    cin >> Password;

    if (Password == "0")
        return;

    totalTransactions = 0;

    // Admin validation check
    if (Email == "admin@gmail.com" && Password == "admin01") {
        currentUser = new User("admin@gmail.com", "System", "admin01", 1);
        // Taking necessary datas Cards and History of transactions of admin
        loadCards();
        loadHistory();

        cout << "\n[Success] Admin Access!" << endl;
        system("pause");
        return;
    }

    ifstream adminFile("admins.dat", ios::binary);
    if (adminFile.is_open()) {
        UserBinary adminRecord;
        while (adminFile.read(reinterpret_cast<char*>(&adminRecord), sizeof(UserBinary))) {
            if (Email == adminRecord.email && Password == adminRecord.password) {
                currentUser = new User(adminRecord.email, adminRecord.username, adminRecord.password, 1);
                loadCards();
                loadHistory();
                adminFile.close();

                cout << "\n[Succes] Administrator! Welcome, " << currentUser->getUsername() << "!" << endl;
                system("pause");
                return;
            }
        }
        adminFile.close();
    }

    // regular user check validatoin
    ifstream inFile("users.dat", ios::binary);
    if (!inFile) {
        cout << "[Error] File not found." << endl;
        system("pause");
        return;
    }

    UserBinary tempRecord;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&tempRecord), sizeof(UserBinary))) {
        if (Email == tempRecord.email && Password == tempRecord.password) {
            currentUser = new User(tempRecord.email, tempRecord.username, tempRecord.password, tempRecord.role);
            // Loading necessary datas
            loadCards();
            loadHistory();
            found = true; // User found successfully
            break;
        }
    }
    inFile.close();

    if (found) {
        cout << "\n[Success] Welcome, " << currentUser->getUsername() << "!" << endl;
    }
    else {
        cout << "\n[Error] Invalid email or password." << endl;
    }
    system("pause");
}

// updateCardsFile function
void AppController::saveCards() {
    ifstream inFile("cards.txt");
    vector<string> otherUsersData;
    string line;

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            if (line.find(currentUser->getEmail()) == string::npos && !line.empty()) { // for searching we use npos which means if email belongs to another
                otherUsersData.push_back(line);
            }
        }
        inFile.close();
    }

    ofstream outFile("cards.txt", ios::trunc);
    for (const string& s : otherUsersData) {
        outFile << s << endl;
    }
    // To not to cause the problem inside of the file, while updating it we need to rewrite the datas
    for (const auto& card : userCards) {
        outFile << currentUser->getEmail() << "," << card.name << "," << card.balance << endl;
    }
    outFile.close();
}

// loadCards function
void AppController::loadCards() {
    userCards.clear(); // We should clear current list before loading
    ifstream cardFile("cards.txt");
    string line;

    if (cardFile.is_open()) {
        while (getline(cardFile, line)) {
            // Check if the line starts with the user's email
            if (line.find(currentUser->getEmail()) == 0) {
                // Parsing email,card name,balance
                size_t firstComma = line.find(','); // size_t cannot be negative, and length of line is the same
                size_t lastComma = line.rfind(',');

                string cName = line.substr(firstComma + 1, lastComma - firstComma - 1);
                string balStr = line.substr(lastComma + 1); // substr to get exactly what we want from long line

                Card temp;
                temp.name = cName;
                temp.balance = stod(balStr); // stod helps to convert line to the numbers double
                userCards.push_back(temp);
            }
        }
        cardFile.close();
    }
}

// loadHistory function
void AppController::loadHistory() {
    for (auto t : history)
        delete t;

    history.clear();

    ifstream inFile("history.txt");
    if (!inFile.is_open())
        return;

    string line;
    while (getline(inFile, line)) {
        if (line.empty())
            continue;

        string parts[5];
        size_t start = 0; // size_t for non negative
        size_t end = 0;

        //  We should search for comma
        for (int i = 0; i < 4; i++) {
            end = line.find(',', start);
            if (end == string::npos) // for validation
                break;
            parts[i] = line.substr(start, end - start); // substr to get exactly what we need
            start = end + 1;
        }
        parts[4] = line.substr(start);

        if (parts[0] == currentUser->getEmail()) {

            double amt = stod(parts[2]);
            string type = parts[1];
            string category = parts[3];
            string cardName = parts[4];

            if (type == "Income") {
                history.push_back(new Income(amt, category, cardName));
            }
            else if (type == "Expense") {
                history.push_back(new Expense(amt, category, cardName));
            }

        }
    }
    inFile.close();
}