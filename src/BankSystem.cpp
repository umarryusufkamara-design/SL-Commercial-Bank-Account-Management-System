#include "BankSystem.h"
#include <iostream>
#include <limits>

using namespace std;

BankSystem::BankSystem() {
    customerIdCounter = 1;
    accountIdCounter = 1001;
    transactionIdCounter = 1;
}

Customer* BankSystem::findCustomerById(int id) {
    for (auto &c : customers) {
        if (c.getId() == id) return &c;
    }
    return nullptr;
}

Account* BankSystem::findAccountByCustomerId(int customerId) {
    for (auto &a : accounts) {
        if (a.getCustomerId() == customerId) return &a;
    }
    return nullptr;
}

Account* BankSystem::findAccountById(int accountId) {
    for (auto &a : accounts) {
        if (a.getAccountId() == accountId) return &a;
    }
    return nullptr;
}


void BankSystem::createCustomer() {
    string name, phone;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter customer name: ";
    getline(cin, name);
    cout << "Enter phone: ";
    getline(cin, phone);

    Customer c(customerIdCounter++, name, phone);
    customers.push_back(c);

    Account a(accountIdCounter++, c.getId(), 0.0);
    accounts.push_back(a);

    cout << "Customer created successfully.\n";
    cout << "Customer ID: " << c.getId() << "\n";
    cout << "Account ID: " << a.getAccountId() << "\n";
}

void BankSystem::viewAllCustomers() {
    if (customers.empty()) {
        cout << "No customers found.\n";
        return;
    }

    for (auto &c : customers) {
        c.display();
        cout << "-------------------\n";
    }
}

void BankSystem::searchCustomer() {
    int id;
    cout << "Enter customer ID: ";
    cin >> id;

    Customer* c = findCustomerById(id);
    if (c) c->display();
    else cout << "Customer not found.\n";
}

void BankSystem::createAccountForCustomer() {
    int customerId;
    cout << "Enter customer ID: ";
    cin >> customerId;

    Customer* c = findCustomerById(customerId);
    if (!c) {
        cout << "Customer not found.\n";
        return;
    }

    Account* existing = findAccountByCustomerId(customerId);
    if (existing) {
        cout << "Account already exists for this customer.\n";
        return;
    }

    Account a(accountIdCounter++, customerId, 0.0);
    accounts.push_back(a);
    cout << "Account created successfully. Account ID: " << a.getAccountId() << "\n";
}

void BankSystem::viewAllAccounts() {
    if (accounts.empty()) {
        cout << "No accounts found.\n";
        return;
    }

    for (auto &a : accounts) {
        a.display();
        cout << "-------------------\n";
    }
}

void BankSystem::viewAllTransactions() {
    if (transactions.empty()) {
        cout << "No transactions found.\n";
        return;
    }

    for (auto &t : transactions) {
        t.display();
        cout << "-------------------\n";
    }
}

void BankSystem::depositMoney(int customerId) {
    Account* a = findAccountByCustomerId(customerId);
    if (!a) {
        cout << "Account not found.\n";
        return;
    }

    double amount;
    cout << "Enter deposit amount: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount.\n";
        return;
    }

    a->deposit(amount);
    transactions.push_back(Transaction(transactionIdCounter++, a->getAccountId(), "Deposit", amount));
    cout << "Deposit successful. New balance: " << a->getBalance() << "\n";
}

void BankSystem::withdrawMoney(int customerId) {
    Account* a = findAccountByCustomerId(customerId);
    if (!a) {
        cout << "Account not found.\n";
        return;
    }

    double amount;
    cout << "Enter withdraw amount: ";
    cin >> amount;

    if (a->withdraw(amount)) {
        transactions.push_back(Transaction(transactionIdCounter++, a->getAccountId(), "Withdraw", amount));
        cout << "Withdrawal successful. New balance: " << a->getBalance() << "\n";
    } else {
        cout << "Insufficient balance or invalid amount.\n";
    }
}

void BankSystem::transferMoney(int customerId) {
    Account* from = findAccountByCustomerId(customerId);
    if (!from) {
        cout << "Your account was not found.\n";
        return;
    }

    int targetAccountId;
    double amount;

    cout << "Enter target account ID: ";
    cin >> targetAccountId;
    cout << "Enter transfer amount: ";
    cin >> amount;

    Account* to = findAccountById(targetAccountId);
    if (!to) {
        cout << "Target account not found.\n";
        return;
    }

    if (from == to) {
        cout << "Cannot transfer to the same account.\n";
        return;
    }

    if (from->withdraw(amount)) {
        to->deposit(amount);
        transactions.push_back(Transaction(transactionIdCounter++, from->getAccountId(), "Transfer Out", amount));
        transactions.push_back(Transaction(transactionIdCounter++, to->getAccountId(), "Transfer In", amount));
        cout << "Transfer successful.\n";
        cout << "Your new balance: " << from->getBalance() << "\n";
    } else {
        cout << "Insufficient balance.\n";
    }
}

void BankSystem::viewCustomerAccount(int customerId) {
    Customer* c = findCustomerById(customerId);
    Account* a = findAccountByCustomerId(customerId);

    if (c) {
        c->display();
        cout << "-------------------\n";
    } else {
        cout << "Customer not found.\n";
        return;
    }

    if (a) {
        a->display();
    } else {
        cout << "Account not found.\n";
    }
}

void BankSystem::viewCustomerTransactions(int customerId) {
    Account* a = findAccountByCustomerId(customerId);
    if (!a) {
        cout << "Account not found.\n";
        return;
    }

    bool found = false;
    for (auto &t : transactions) {
        if (t.getAccountId() == a->getAccountId()) {
            t.display();
            cout << "-------------------\n";
            found = true;
        }
    }

    if (!found) cout << "No transactions found for this customer.\n";
}

void BankSystem::customerMenu(int customerId) {
    int choice;
    do {
        cout << "\n===== CUSTOMER MENU =====\n";
        cout << "1. View Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Money\n";
        cout << "5. View Transaction History\n";
        cout << "0. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: viewCustomerAccount(customerId); break;
            case 2: depositMoney(customerId); break;
            case 3: withdrawMoney(customerId); break;
            case 4: transferMoney(customerId); break;
            case 5: viewCustomerTransactions(customerId); break;
            case 0: cout << "Logging out...\n"; break;
            default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 0);
}

void BankSystem::adminMenu() {
    int choice;
    do {
        cout << "\n===== ADMIN MENU =====\n";
        cout << "1. Create Customer\n";
        cout << "2. Create Account for Existing Customer\n";
        cout << "3. View All Customers\n";
        cout << "4. Search Customer by ID\n";
        cout << "5. View All Accounts\n";
        cout << "6. View All Transactions\n";
        cout << "0. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createCustomer(); break;
            case 2: createAccountForCustomer(); break;
            case 3: viewAllCustomers(); break;
            case 4: searchCustomer(); break;
            case 5: viewAllAccounts(); break;
            case 6: viewAllTransactions(); break;
            case 0: cout << "Logging out...\n"; break;
            default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 0);
}

void BankSystem::run() {
    int choice;
    do {
        cout << "\n===== BANK SYSTEM =====\n";
        cout << "1. Admin Login by ID\n";
        cout << "2. Customer Login by ID\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int adminId;
            cout << "Enter Admin ID: ";
            cin >> adminId;

            if (adminId == 1) {
                adminMenu();
            } else {
                cout << "Invalid Admin ID. Use 1.\n";
            }
        } else if (choice == 2) {
            int customerId;
            cout << "Enter Customer ID: ";
            cin >> customerId;

            Customer* c = findCustomerById(customerId);
            if (c) {
                customerMenu(customerId);
            } else {
                cout << "Customer not found.\n";
            }
        } else if (choice == 0) {
            cout << "Exiting system...\n";
        } else {
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}
