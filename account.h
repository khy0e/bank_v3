#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
using namespace std;

class Account {
public:
    Account(const string& accountNumber, const string& owner, double balance);

    string getAccountNumber() const;
    string getOwner() const;
    double getBalance() const;

    void deposit(double amount);
    bool withdraw(double amount);

private:
    string accountNumber;
    string owner;
    double balance;
    vector<pair<string, double>> transactions; // 기록 저장용 예시
};

#endif // ACCOUNT_H

