#include "Transaction.h"

Transaction::Transaction() {
    transactionId = 0;
    accountId = 0;
    type = "";
    amount = 0.0;
}

Transaction::Transaction(int transactionId, int accountId, std::string type, double amount) {
    this->transactionId = transactionId;
    this->accountId = accountId;
    this->type = type;
    this->amount = amount;
}

int Transaction::getTransactionId() const { return transactionId; }
int Transaction::getAccountId() const { return accountId; }
std::string Transaction::getType() const { return type; }
double Transaction::getAmount() const { return amount; }

void Transaction::setTransactionId(int transactionId) { this->transactionId = transactionId; }
void Transaction::setAccountId(int accountId) { this->accountId = accountId; }
void Transaction::setType(std::string type) { this->type = type; }
void Transaction::setAmount(double amount) { this->amount = amount; }

void Transaction::display() const {
    std::cout << "Transaction ID: " << transactionId << "\n";
    std::cout << "Account ID: " << accountId << "\n";
    std::cout << "Type: " << type << "\n";
    std::cout << "Amount: " << amount << "\n";
}
