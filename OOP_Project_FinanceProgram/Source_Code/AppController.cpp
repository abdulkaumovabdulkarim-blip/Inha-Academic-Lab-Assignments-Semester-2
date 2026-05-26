// AppController.cpp
#include "AppController.h"
#include <fstream>

using namespace std;

// We Initialize static member zero
int AppController::totalTransactions = 0;

// Constructor to run the program and set CurrentUser zero at first so program know that no one is registered yet
AppController::AppController() : currentUser(nullptr), isRunning(true) {}

// Destructor to leaning up memory
AppController::~AppController() {
    delete currentUser;
    for (size_t i = 0; i < history.size(); i++) {
        delete history[i];
    }
}

// Static member function
void AppController::plusTransactions() {
    totalTransactions++; // We add one
}

// Main start function
// We have to call it in main.cpp file
void AppController::start() {
    while (isRunning) {
        if (currentUser == nullptr) {
            WelcomeMenu();
        }
        else {
            MainMenu();
        }
    }
    cout << "\nThank you for using Finance App. Goodbye!" << endl;
}

// showWelcomeMenu function
void AppController::WelcomeMenu() {
    system("cls");
    cout << "---------WELCOME FINANCE APP!-----------" << endl;
    cout << "1. Sign In" << endl;
    cout << "2. Sign Up" << endl;
    cout << "0. Exit" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Choice: ";

    int choice;
    // Check if not number
    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    // Call function depending on user choice
    switch (choice) {
    case 1:
        SignIn();
        break;
    case 2:
        SignUp();
        break;
    case 0:
        isRunning = false;
        break;
    default:
        cout << "Invalid choice! Try again." << endl;
        system("pause");
        break;
    }
}