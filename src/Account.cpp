#include "Account.h"

Account::Account() {
    accountId = 0;
    customerId = 0;
    balance = 0.0;
}

Account::Account(int accountId, int customerId, double balance) {
    this->accountId = accountId;
    this->customerId = customerId;
    this->balance = balance;
}

int Account::getAccountId() const { return accountId; }
int Account::getCustomerId() const { return customerId; }
double Account::getBalance() const { return balance; }

void Account::setAccountId(int accountId) { this->accountId = accountId; }
void Account::setCustomerId(int customerId) { this->customerId = customerId; }
void Account::setBalance(double balance) { this->balance = balance; }

void Account::deposit(double amount) {
    if (amount > 0) balance += amount;
}

bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

void Account::display() const {
    std::cout << "Account ID: " << accountId << "\n";
    std::cout << "Customer ID: " << customerId << "\n";
    std::cout << "Balance: " << balance << "\n";
}
