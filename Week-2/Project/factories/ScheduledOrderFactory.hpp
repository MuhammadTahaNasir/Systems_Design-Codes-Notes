#ifndef SCHEDULED_ORDER_FACTORY_HPP
#define SCHEDULED_ORDER_FACTORY_HPP

#include "factories/OrderFactory.hpp"

class ScheduledOrderFactory : public OrderFactory {
public:
    Order* createOrder(User* user, Cart* cart, Seller* seller,
                       std::vector<Product> products, PaymentStrategy* ps,
                       std::string orderType, double totalCost) override {
        Order* order = nullptr;
        if (orderType == "Delivery") {
            order = new DeliveryOrder(user, seller, products, ps, totalCost, "Scheduled Time");
        } else if (orderType == "Pickup") {
            order = new PickupOrder(user, seller, products, ps, totalCost, "Scheduled Time");
        }
        return order;
    }
};

#endif