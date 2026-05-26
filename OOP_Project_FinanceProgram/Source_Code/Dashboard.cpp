// Dashboard.cpp
#include "AppController.h"
#include <fstream>
#include <iomanip>

using namespace std;

// handleTransaction  function
void AppController::handleTransaction() {
    try {
        system("cls");
        int cardIndex, type;
        double amount;
        string category;

        if (userCards.empty())
            throw "You don't have any cards!";

        cout << "--- SELECT CARD ---" << endl;
        for (int i = 0; i < userCards.size(); i++) {
            cout << i + 1 << ". " << userCards[i].name << " (" << userCards[i].balance << ")\n";
        }
        cout << "Enter choice: ";

        cin >> cardIndex;
        cardIndex--; // minus one to index
        if (cardIndex < 0 || cardIndex >= userCards.size())
            throw "Invalid card selection!";

        cout << "\n1. Income" << endl;;
        cout << "2. Expense" << endl;
        cout << "0. Cancel" << endl;
        cout << "Choice: ";
        cin >> type;

        if (type == 0)
            return;

        cout << "Amount: ";
        cin >> amount;

        if (amount <= 0)
            throw "Amount must be positive!";

        // Expense cannot exceed balance
        if (type == 2 && amount > userCards[cardIndex].balance) {
            throw "Insufficient funds on this card!";
        }

        cin.ignore();
        cout << "Category: ";       
        getline(cin, category);

        // Runtime Polymorphism
        // We save all history transactions to load them when user signIns
        if (type == 1) {
            userCards[cardIndex].balance += amount;
            history.push_back(new Income(amount, category, userCards[cardIndex].name));
            saveTransaction(history.back(), userCards[cardIndex].name);
        }
        else {
            userCards[cardIndex].balance -= amount;
            history.push_back(new Expense(amount, category, userCards[cardIndex].name));
            saveTransaction(history.back(), userCards[cardIndex].name);
        }

        plusTransactions();
        saveCards();

        cout << "\n[Success] Transaction completed!" << endl;
    }

    catch (const char* msg) {
        cout << "\n[ERROR]: " << msg << endl;
    }

    system("pause");
}

// saveTransactionToFile function
void AppController::saveTransaction(Transaction* t, string cardName) {
    ofstream outFile("history.txt", ios::app);
    if (outFile.is_open()) {
        if (currentUser) {
            // we save history along with emai in order to Correctly load them when user signIns again
            outFile << currentUser->getEmail() << "," << t->getType() << "," << t->getAmount() << "," << t->getCategory() << "," << cardName << endl;
        }
        outFile.close();
    }
}

// showDashboard function
void AppController::MainMenu() {
    system("cls");
    int choice;

    cout << "--- FINANCE APP DASHBOARD ---" << endl;
    cout << "User: " << currentUser->getUsername() << endl;
    cout << "Total operations in this session: " << totalTransactions << endl;
    cout << "-----------------------------\n";
    cout << "1. New Transaction" << endl;
    cout << "2. View Cards" << endl;
    cout << "3. View History" << endl;
    cout << "4. Logout" << endl;

    // To access admin panel if role is 1
    if (currentUser->getRole() == 1) {
        cout << "5. ADMIN PANEL" << endl;
    }
    cout << "0. Exit" << endl;
    cout << "Choice: ";   
    cin >> choice;

    if (choice == 1) 
        handleTransaction();

    else if (choice == 2) {
        bool CardMenu = true;
        int cardChoice;

        while (CardMenu) {
            system("cls");
            cout << "--- YOUR CARDS ---" << endl;
            if (userCards.empty()) {
                cout << "No cards found." << endl;
            }
            else {
                for (int i = 0; i < userCards.size(); i++) {
                    cout << i + 1 << ". " << setw(15) << left << userCards[i].name << ": $" << userCards[i].balance << endl;
                }
            }
            cout << "-----------------" << endl;
            cout << "1. Add New Card" << endl;
            cout << "2. Delete Card" << endl;
            cout << "0. Back" << endl;
            cout << "Choice: ";
            cin >> cardChoice;

            if (cardChoice == 1)
                addCard();
            else if (cardChoice == 2)
                deleteCard();
            else if (cardChoice == 0)
                CardMenu = false;
        }
    }
    else if (choice == 3) {
        bool HistoryMenu = true;
        int histChoice;

        while (HistoryMenu) {
            system("cls");
            cout << "--- TRANSACTION HISTORY ---\n";
            cout << "1. All" << endl;
            cout << "2. Income" << endl;
            cout << "3. Expense" << endl;
            cout << "0. Back" << endl;
            cout << "Choice: ";
            cin >> histChoice;

            if (histChoice == 0) {
               HistoryMenu = false;
                continue;
            }

            system("cls");
            cout << "--- RESULTS ---" << endl;
            
            bool found = false;

            // Ask to filter
            for (int i = 0; i < history.size(); i++) {
                Transaction* t = history[i]; // Explicit base class pointer

                if (histChoice == 1 || (histChoice == 2 && t->getType() == "Income") || (histChoice == 3 && t->getType() == "Expense")) {
                    t->print(); // Invoking Virtual function
                    found = true;
                }
            }

            if (!found)
                cout << "No transactions found for this choice." << endl;
            system("pause");
        }
    }
    else if (choice == 4) {
        // Logout
        delete currentUser;

        currentUser = nullptr;

        for (int i = 0; i < history.size(); i++) {
            delete history[i];
        }

        history.clear();
    }
    else if (choice == 5 && currentUser->getRole() == 1) {
        AdminPanel();
    }
    else if (choice == 0)
        isRunning = false;
    else {
        cout << "Invalid Choice!" << endl;
        system("pause");
    }
}

// addCard function to register a new card
void AppController::addCard() {
    try {
        string cardName;
        double bal;

        cout << "\n--- ADD NEW CARD---" << endl;
        cout << "Enter Card Name: ";
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        getline(cin, cardName);

        if (cardName.empty()) {
            throw "Card name cannot be empty!";
        }

        cout << "Initial Balance: ";
        // Safe input validation against char-injection
        if (!(cin >> bal)) {
            cin.clear(); // We clear stream error flag
            cin.ignore(1000, '\n');
            throw "Invalid balance! Please enter a number!";
        }
        if (bal < 0) {
            throw "Initial balance cannot be negative!";
        }

        Card newCard;
        newCard.name = cardName;
        newCard.balance = bal;

        // We push new structure object into the vector
        userCards.push_back(newCard);

        // We immediately rewrite text database using our updated info
        saveCards();

        cout << "\n[Success] Card '" << cardName << "' successfully added!\n";
    }
    catch (const char* message) {
        cout << "\n[ERROR]: " << message << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    system("pause");
}

// deleteCard function using iterator-based vector item removal
void AppController::deleteCard() {
    try {
        // We preventing a user from having 0 cards
        if (userCards.size() <= 1) {
            throw "You must keep at least one active card account!";
        }

        int index;
        char confirm;

        cout << "\n--- DELETE CARD ---" << endl;
        for (int i = 0; i < userCards.size(); i++) {
            cout << i + 1 << ". " << userCards[i].name << " (" << userCards[i].balance << ")\n";
        }
        cout << "Enter card number to delete (0 to cancel): ";
        if (!(cin >> index)) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw "Invalid entry! Card selection must be a number.";
        }

        if (index == 0)
            return; // User chose 0 to cancel

        index--; // minus one to correct index


        if (index < 0 || index >= userCards.size()) {
            throw "No such card exists.";
        }

        cout << "Are you sure you want to delete " << userCards[index].name << "? (y/n): ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            userCards.erase(userCards.begin() + index);

            // Rewrite database text file with remaining cards via dynamic trunc implementation
            saveCards();

            cout << "\n[Success] Card permanently removed from your account.\n";
        }
    }
    catch (const char* message) {
        cout << "\n[ERROR]: " << message << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    system("pause");
}