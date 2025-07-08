#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product {
private:
    std::string code;
    std::string name;
    double price;
    std::string category;

public:
    Product(std::string code, std::string name, double price, std::string category)
        : code(code), name(name), price(price), category(category) {}

    std::string getCode() const { return code; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    std::string getCategory() const { return category; }
};

#endif