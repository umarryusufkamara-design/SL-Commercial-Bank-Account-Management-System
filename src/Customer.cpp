#include "Customer.h"

Customer::Customer() {
    id = 0;
    name = "";
    phone = "";
}

Customer::Customer(int id, std::string name, std::string phone) {
    this->id = id;
    this->name = name;
    this->phone = phone;
}

int Customer::getId() const { return id; }
std::string Customer::getName() const { return name; }
std::string Customer::getPhone() const { return phone; }

void Customer::setId(int id) { this->id = id; }
void Customer::setName(std::string name) { this->name = name; }
void Customer::setPhone(std::string phone) { this->phone = phone; }

void Customer::display() const {
    std::cout << "Customer ID: " << id << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Phone: " << phone << "\n";
}
