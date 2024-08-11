#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H

#include <map>
#include <memory>
#include <string>
#include "account.h"
using namespace std;

class BankingSystem {
public:
    void createAccount(const string& owner, const string& accountNumber, double initialBalance);
    shared_ptr<Account> getAccount(const string& accountNumber);
    void deposit(const string& accountNumber, double amount);
    bool withdraw(const string& accountNumber, double amount);
    vector<shared_ptr<Account>> getAllAccounts(const string& owner) const;

private:
    map<string, shared_ptr<Account>> accounts;
};

#endif // BANKINGSYSTEM_H

