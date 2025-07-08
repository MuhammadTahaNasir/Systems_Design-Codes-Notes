#ifndef ORDER_FACTORY_HPP
#define ORDER_FACTORY_HPP

#include "models/Order.hpp"
#include "models/User.hpp"
#include "models/Cart.hpp"
#include "models/Seller.hpp"
#include "models/Product.hpp"
#include "strategies/PaymentStrategy.hpp"

class OrderFactory {
public:
    virtual Order* createOrder(User* user, Cart* cart, Seller* seller,
                              std::vector<Product> products, PaymentStrategy* ps,
                              std::string orderType, double totalCost) = 0;
    virtual ~OrderFactory() {}
};

#endif