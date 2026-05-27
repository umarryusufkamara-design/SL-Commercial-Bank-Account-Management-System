#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>

class Account {
private:
    int accountId;
    int customerId;
    double balance;

public:
    Account();
    Account(int accountId, int customerId, double balance);

    int getAccountId() const;
    int getCustomerId() const;
    double getBalance() const;

    void setAccountId(int accountId);
    void setCustomerId(int customerId);
    void setBalance(double balance);

    void deposit(double amount);
    bool withdraw(double amount);

    void display() const;
};

#endif
