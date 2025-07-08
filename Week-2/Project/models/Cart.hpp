#ifndef CART_HPP
#define CART_HPP

#include <vector>
#include "Product.hpp"
#include "Seller.hpp"

class Cart {
private:
    Seller* seller;
    std::vector<Product> products;
    double totalPrice;

public:
    Cart() : seller(nullptr), totalPrice(0.0) {}

    void addProduct(Product product) {
        if (seller) {
            products.push_back(product);
            totalPrice += product.getPrice();
        }
    }

    void setSeller(Seller* sel) { seller = sel; }
    bool isEmpty() const { return products.empty(); }
    void clear() { products.clear(); totalPrice = 0.0; }
    double getTotalCost() const { return totalPrice; }
    Seller* getSeller() const { return seller; }
    std::vector<Product> getProducts() const { return products; }
};

#endif