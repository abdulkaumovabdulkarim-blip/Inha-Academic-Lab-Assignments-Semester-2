// Transaction.h
#pragma once
#include <string>
#include <iostream>

using namespace std;

// Abstract Base Class
class Transaction {
protected:
    double amount;
    string category;
    string cardName;
public:
    // Constructor
    Transaction(double amt, string cat, string card) : amount(amt), category(cat), cardName(card) {}

    // Virtual destructor for polymorphism
    virtual ~Transaction() {}

    // Pure virtual function
    // making class abstarkt.
    virtual void print() const = 0; // We make them const for savity reasons
    virtual string getType() const = 0;
    double getAmount() const {
        return amount;
    }
    string getCategory() const {
        return category;
    }
    string getCardName() const {
        return cardName;
    }
};

// Inheritance income class public from transaction
class Income : public Transaction {
public:
    Income(double a, string c, string crd) : Transaction(a, c, crd) {}

    // Overriding pure virtual functions
    void print() const override {
        cout << "[INCOME]  Card: " << cardName << " | Amount: +" << amount << " | Category: " << category << endl;
    }
    string getType() const override {
        return "Income";
    }
};

// Inheritance expense class public from transaction
class Expense : public Transaction {
public:
    Expense(double a, string c, string crd) : Transaction(a, c, crd) {}

    void print() const override {
        cout << "[EXPENSE] Card: " << cardName << " | Amount: -" << amount << " | Category: " << category << endl;
    }
    string getType() const override {
        return "Expense";
    }
};