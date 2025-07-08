#ifndef PICKUP_ORDER_HPP
#define PICKUP_ORDER_HPP

#include "Order.hpp"

class PickupOrder : public Order {
private:
    std::string sellerAddress;

public:
    PickupOrder(User* user, Seller* seller, std::vector<Product> products,
                PaymentStrategy* ps, double total, std::string scheduledTime)
        : Order(user, seller, products, ps, total, scheduledTime),
          sellerAddress(seller->getAddress()) {}

    std::string getType() override { return "Pickup"; }
    std::string getSellerAddress() const { return sellerAddress; }
};

#endif