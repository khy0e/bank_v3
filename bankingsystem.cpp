#include "bankingsystem.h"
#include <iostream>
#include <stdexcept>

void BankingSystem::createAccount(const string& owner, const string& accountNumber, double initialBalance) {
    if (accounts.find(accountNumber) == accounts.end()) {
        accounts[accountNumber] = make_shared<Account>(accountNumber, owner, initialBalance);
    } else {
        throw runtime_error("Account already exists.");
    }
}

shared_ptr<Account> BankingSystem::getAccount(const string& accountNumber) {
    auto it = accounts.find(accountNumber);
    if (it != accounts.end()) {
        return it->second;
    }
    throw runtime_error("Account not found.");
}

void BankingSystem::deposit(const string& accountNumber, double amount) {
    auto account = getAccount(accountNumber);
    if (account) {
        account->deposit(amount);
    }
}

bool BankingSystem::withdraw(const string& accountNumber, double amount) {
    auto account = getAccount(accountNumber);
    if (account) {
        return account->withdraw(amount);
    }
    return false;
}

vector<shared_ptr<Account>> BankingSystem::getAllAccounts(const string& owner) const {
    vector<shared_ptr<Account>> ownerAccounts;
    for (const auto& pair : accounts) {
        if (pair.second->getOwner() == owner) {
            ownerAccounts.push_back(pair.second);
        }
    }
    return ownerAccounts;
}
