#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>

class Transaction {
private:
    int transactionId;
    int accountId;
    std::string type;
    double amount;

public:
    Transaction();
    Transaction(int transactionId, int accountId, std::string type, double amount);

    int getTransactionId() const;
    int getAccountId() const;
    std::string getType() const;
    double getAmount() const;

    void setTransactionId(int transactionId);
    void setAccountId(int accountId);
    void setType(std::string type);
    void setAmount(double amount);

    void display() const;
};

#endif
