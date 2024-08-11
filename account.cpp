#include "account.h"


Account::Account(const string& accountNumber, const string& owner, double balance)
    : accountNumber(accountNumber), owner(owner), balance(balance) {}

string Account::getAccountNumber() const {
    return accountNumber;
}

string Account::getOwner() const {
    return owner;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    balance += amount;
    transactions.push_back({"Deposit", amount});
}

bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        transactions.push_back({"Withdraw", amount});
        return true;
    }
    return false;
}


