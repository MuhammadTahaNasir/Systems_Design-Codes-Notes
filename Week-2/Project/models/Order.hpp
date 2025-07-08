#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <vector>
#include "User.hpp"
#include "Seller.hpp"
#include "Product.hpp"
#include "PaymentStrategy.hpp"

class Order {
private:
    static int nextOrderId;
    std::string orderId;
    User* user;
    Seller* seller;
    std::vector<Product> products;
    PaymentStrategy* paymentStrategy;
    double total;
    std::string scheduledTime;

public:
    Order(User* user, Seller* seller, std::vector<Product> products,
          PaymentStrategy* ps, double total, std::string scheduledTime)
        : orderId("ORD" + std::to_string(nextOrderId++)),
          user(user), seller(seller), products(products),
          paymentStrategy(ps), total(total), scheduledTime(scheduledTime) {}

    bool processPayment() {
        if (paymentStrategy) {
            paymentStrategy->pay(total);
            return true;
        }
        std::cout << "Please choose payment mode first!" << std::endl;
        return false;
    }

    virtual std::string getType() = 0;

    std::string getId() const { return orderId; }
    User* getUser() const { return user; }
    Seller* getSeller() const { return seller; }
    std::vector<Product> getProducts() const { return products; }
    double getTotal() const { return total; }
    std::string getScheduledTime() const { return scheduledTime; }
};

int Order::nextOrderId = 1;

#endif