

#ifndef FILEMANGER_FILEMANAGER_H
#define FILEMANGER_FILEMANAGER_H
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
//---------------------------------------------
class FileManager{
protected:
    string userFile;
    string gamesFile;
    string transactionsFile;
public:
    void readUserFile();
    void readGamesFile();
    void writeTransactionFile(const string& filename, const string& transactionCode);
    void updateUsersFile(const string& filename, const string& username, const string& userType, const int& balance);
    void updateGamesFile(const string& filename, const string& gamePrice, const string& gameName, const string& sellerName);
    void readTransactionsFile();

};

//---------------------------------------------
class Game {
private:

    string gameName="";
    string userName="";
    double price=0;

public:
    Game(const std::string& g, const std::string& u, double p);
    void setGameName(string g);
    void setSellerName(string u);
    void setPrice(double p);
    string getGameName();
    string getSellerName();
    double getGamePrice();

};

//---------------------------------------------
class InputValidator {
public:
    bool isStringInRange(string& u);
    bool validateUser(string& u, string& uType);
    bool validateGame(string& g);
    bool validatePrice(double p);
};
//---------------------------------------------
class Session {
private:
    User* currentSession;

public:
    Session(User* currentSession);
    Session();
    User* getSession();
    User* setSession(User* currentSession);
    void startSession(User* currentSession);
    void endSession(User* currentSession);
    User* getCurrentSession() const;
};
//---------------------------------------------
class Transaction{
protected:
    string transactionCode;
public:
    bool parse();
};
//---------------------------------------------



class TransactionProcessor {
private:
    FileManager& fileManager;  // Reference to FileManager object
    Session& currentSession;   // Reference to Session object

    // Private helper method to check if a user is logged in
    bool isLoggedIn;

public:
    // Constructor with references to FileManager and Session objects
    TransactionProcessor(FileManager& fm, Session& session);

    // Method to process a transaction
    void processTransaction(const std::string& transactionCode);
    bool isUserLoggedIn() const;
private:
    // Private helper methods for each transaction type
    void processLogin();
    void processLogout();
    void processCreate();
    void processDelete();
    void processSell();
    void processBuy();
    void processRefund();
    void processAddCredit();
    void processList();
    void processUserList();
    void processEndOfSession();

    // Private helper method to log transaction details
    void logTransaction(const std::string& transactionDetails);
};
//---------------------------------------------
class User {
private:
    string username;
    string userType;
    double balance;

public:
    User(string username, string userType, double balance);
    User();
    string getUsername();
    string getUserType();
    double getBalance();
    void setBalance(double balance);
    void setUsername(string username);
    void setUserType(string userType);
    void deposit(double amount);
    void withdraw(double amount);
};
//---------------------------------------------

#endif 