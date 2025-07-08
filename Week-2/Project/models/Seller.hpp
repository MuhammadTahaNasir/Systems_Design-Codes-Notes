#ifndef SELLER_HPP
#define SELLER_HPP

#include <string>
#include <vector>
#include "Product.hpp"

class Seller {
private:
    static int nextSellerId;
    std::string sellerId;
    std::string name;
    std::string address;
    std::vector<Product> products;

public:
    Seller(std::string name, std::string address, std::vector<Product> products)
        : sellerId("SEL" + std::to_string(nextSellerId++)),
          name(name), address(address), products(products) {}

    std::string getId() const { return sellerId; }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::vector<Product> getProducts() const { return products; }
};

int Seller::nextSellerId = 1;

#endif