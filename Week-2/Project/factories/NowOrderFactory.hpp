#ifndef NOW_ORDER_FACTORY_HPP
#define NOW_ORDER_FACTORY_HPP

#include "OrderFactory.hpp"
#include "utils/TimeUtils.hpp"

class NowOrderFactory : public OrderFactory {
public:
    Order* createOrder(User* user, Cart* cart, Seller* seller,
                       std::vector<Product> products, PaymentStrategy* ps,
                       std::string orderType, double totalCost) override {
        Order* order = nullptr;
        if (orderType == "Delivery") {
            order = new DeliveryOrder(user, seller, products, ps, totalCost, TimeUtils::getCurrentTime());
        } else if (orderType == "Pickup") {
            order = new PickupOrder(user, seller, products, ps, totalCost, TimeUtils::getCurrentTime());
        }
        return order;
    }
};

#endif