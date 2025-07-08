#include <iostream>
#include "Bazaar.hpp"
#include "JazzCashPayment.hpp"

int main() {
    Bazaar bazaar;
    User user("1001", "Ahmed", "Karachi");
    std::cout << "User " << user.getName() << " is active." << std::endl;

    // Search products by category
    std::vector<Seller> sellers = bazaar.searchProductsByCategory("Clothing");
    if (sellers.empty()) {
        std::cout << "No sellers found!" << std::endl;
        return 0;
    }
    for (const auto& seller : sellers) {
        std::cout << "Found Seller: " << seller.getName() << std::endl;
    }

    // Select seller
    bazaar.selectSeller(&user, &sellers[0]);
    std::cout << "Selected Seller: " << sellers[0].getName() << std::endl;

    // Add products to cart
    bazaar.addToCart(&user, "SK001");
    bazaar.addToCart(&user, "PH001");
    bazaar.printUserCart(&user);

    // Checkout and pay
    JazzCashPayment jazzCash("03211234567");
    Order* order = bazaar.checkoutNow(&user, &jazzCash, "Delivery");
    if (order) {
        bazaar.payForOrder(order);
        std::cout << "Payment done!" << std::endl;
    }

    // Cleanup
    for (auto order : OrderManager::getInstance()->listOrders()) {
        delete order;
    }
    return 0;
}