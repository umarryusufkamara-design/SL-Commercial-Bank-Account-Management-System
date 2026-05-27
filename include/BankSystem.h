#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include <vector>
#include "Customer.h"
#include "Account.h"
#include "Transaction.h"

class BankSystem {
private:
    std::vector<Customer> customers;
    std::vector<Account> accounts;
    std::vector<Transaction> transactions;

    int customerIdCounter;
    int accountIdCounter;
    int transactionIdCounter;

    Customer* findCustomerById(int id);
    Account* findAccountByCustomerId(int customerId);
    Account* findAccountById(int accountId);
    void customerMenu(int customerId);
    void adminMenu();

public:
    BankSystem();
    void run();

    void createCustomer();
    void viewAllCustomers();
    void searchCustomer();
    void createAccountForCustomer();
    void viewAllAccounts();
    void viewAllTransactions();

    void depositMoney(int customerId);
    void withdrawMoney(int customerId);
    void transferMoney(int customerId);
    void viewCustomerAccount(int customerId);
    void viewCustomerTransactions(int customerId);
};

#endif
