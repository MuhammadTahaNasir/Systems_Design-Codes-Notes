#ifndef NOTIFICATION_SERVICE_HPP
#define NOTIFICATION_SERVICE_HPP

#include <string>
#include "models/Order.hpp"

class NotificationService {
public:
    void notify(Order* order) {
        std::cout << "Notification: New " << order->getType() << " order placed!\n"
                  << "Order ID: " << order->getId() << "\n"
                  << "User: " << order->getUser()->getName() << "\n"
                  << "Seller: " << order->getSeller()->getName() << "\n"
                  << "Products: ";
        for (const auto& product : order->getProducts()) {
            std::cout << product.getName() << " (" << product.getPrice() << " PKR), ";
        }
        std::cout << "\nTotal: " << order->getTotal() << " PKR\n"
                  << "Scheduled for: " << order->getScheduledTime() << std::endl;
    }
};

#endif