// User.h
#pragma once
#include <string>
#include <vector>

using namespace std;

// Fixed-length structure for binary file memory, we use char arrays instead of string for specific record sizes
// struct UserBinary is used as a file database only
struct UserBinary {
    char email[40] = ""; // Initialaizing them to insure no garbage there
    char username[30] = "";
    char password[30] = "";
    int role = 0;
};

// Structure for name and balance of cards
struct Card {
    string name;
    double balance = 0.0;
};

// User class
// class User is our runtime operational class. Not for writing to the file
class User {
private:
    string email;
    string username;
    string password;
    int role;
public:
    // User Constructor
    User(string em, string un, string ps, int r) : email(em), username(un), password(ps), role(r) {}

    // Destructor
    ~User() {}

    // We need only getters
    string getEmail() const {
        return email;
    }
    string getUsername() const {
        return username;
    }
    int getRole() const {
        return role;
    }
};