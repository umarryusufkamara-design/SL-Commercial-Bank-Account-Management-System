#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>

class Customer {
private:
    int id;
    std::string name;
    std::string phone;

public:
    Customer();
    Customer(int id, std::string name, std::string phone);

    int getId() const;
    std::string getName() const;
    std::string getPhone() const;

    void setId(int id);
    void setName(std::string name);
    void setPhone(std::string phone);

    void display() const;
};

#endif
