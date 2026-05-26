#pragma once
// AppController.h
#include "User.h" // We include structs UserBinary, Card and class User
#include "Transaction.h" // We also include main class for all types of Transaction
#include <vector>
#include <string>

class AppController {
private:
    User* currentUser;
    vector<Card> userCards; // User has multiple cards
    vector<Transaction*> history; // Class transaction is abstract that's why we use pointer
    bool isRunning;

    // Static member to show number of transactions
    static int totalTransactions;
public:
    // AppController constructor
    AppController();
    // Destructor is important for deleting current user and also abstract class "Transaction"
    ~AppController(); 

    // We devide group of functions for clarity of the code
    // AppController.cpp functions
    void start();
    void SignIn();
    void SignUp();
    void loadCards();
    void saveCards();
    void WelcomeMenu();

    // Dashboard.cpp functions
    void MainMenu();
    void handleTransaction();
    void saveTransaction(Transaction* t, string cardName);
    void deleteCard();
    void addCard();
    void loadHistory();


    // Admin.cpp functions
    void AdminPanel();
    void AllUsers();
    void deleteUser();
    void Admins();

    // Static method function
    static void plusTransactions();
};