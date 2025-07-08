#ifndef ORDER_MANAGER_HPP
#define ORDER_MANAGER_HPP

#include <vector>
#include "models/Order.hpp"

class OrderManager {
private:
    static OrderManager* instance;
    std::vector<Order*> orders;
    OrderManager() {}

public:
    static OrderManager* getInstance() {
        if (!instance) instance = new OrderManager();
        return instance;
    }

    void addOrder(Order* order) {
        orders.push_back(order);
    }

    std::vector<Order*> listOrders() {
        return orders;
    }
};

OrderManager* OrderManager::instance = nullptr;

#endif