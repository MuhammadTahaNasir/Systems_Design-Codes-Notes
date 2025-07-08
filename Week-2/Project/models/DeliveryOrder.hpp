#ifndef DELIVERY_ORDER_HPP
#define DELIVERY_ORDER_HPP

#include "Order.hpp"

class DeliveryOrder : public Order {
private:
    std::string userAddress;

public:
    DeliveryOrder(User* user, Seller* seller, std::vector<Product> products,
                  PaymentStrategy* ps, double total, std::string scheduledTime)
        : Order(user, seller, products, ps, total, scheduledTime),
          userAddress(user->getAddress()) {}

    std::string getType() override { return "Delivery"; }
    std::string getUserAddress() const { return userAddress; }
};

#endif