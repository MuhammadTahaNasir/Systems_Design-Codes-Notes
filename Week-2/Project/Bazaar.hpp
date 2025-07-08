#ifndef BAZAAR_HPP
#define BAZAAR_HPP

#include <string>
#include <vector>
#include "managers/SellerManager.hpp"
#include "managers/OrderManager.hpp"
#include "models/User.hpp"
#include "factories/OrderFactory.hpp"
#include "services/NotificationService.hpp"
#include "strategies/PaymentStrategy.hpp"

class Bazaar {
private:
    SellerManager* sellerManager;
    OrderManager* orderManager;
    NotificationService notificationService;

    void initializeSellers() {
        std::vector<Product> products = {
            Product("SK001", "Embroidered Shalwar Kameez", 3500.0, "Clothing"),
            Product("PH001", "Samsung Galaxy A14", 45000.0, "Electronics")
        };
        Seller s1("Anarkali Shop", "Lahore", products);
        sellerManager->addSeller(s1);
    }

public:
    Bazaar() {
        sellerManager = SellerManager::getInstance();
        orderManager = OrderManager::getInstance();
        initializeSellers();
    }

    std::vector<Seller> searchProductsByCategory(std::string category) {
        return sellerManager->searchByCategory(category);
    }

    std::vector<Seller> searchProductsByLocation(std::string location) {
        return sellerManager->searchByLocation(location);
    }

    void selectSeller(User* user, Seller* seller) {
        user->getCart().setSeller(seller);
    }

    void addToCart(User* user, std::string productCode) {
        Seller* seller = user->getCart().getSeller();
        if (!seller) {
            std::cout << "Please select a seller first!" << std::endl;
            return;
        }
        for (const auto& product : seller->getProducts()) {
            if (product.getCode() == productCode) {
                user->getCart().addProduct(product);
            }
        }
    }

    Order* checkoutNow(User* user, PaymentStrategy* ps, std::string orderType) {
        return checkout(user, ps, orderType, new NowOrderFactory());
    }

    Order* checkoutScheduled(User* user, PaymentStrategy* ps, std::string orderType, std::string scheduledTime) {
        return checkout(user, ps, orderType, new ScheduledOrderFactory());
    }

private:
    Order* checkout(User* user, PaymentStrategy* ps, std::string orderType, OrderFactory* factory) {
        Cart& cart = user->getCart();
        if (cart.isEmpty()) {
            std::cout << "Cart is empty!" << std::endl;
            return nullptr;
        }
        Seller* seller = cart.getSeller();
        std::vector<Product> products = cart.getProducts();
        double total = cart.getTotalCost();
        Order* order = factory->createOrder(user, &cart, seller, products, ps, orderType, total);
        orderManager->addOrder(order);
        return order;
    }

public:
    bool payForOrder(Order* order) {
        bool paymentSuccess = order->processPayment();
        if (paymentSuccess) {
            notificationService.notify(order);
            order->getUser()->getCart().clear();
        }
        return paymentSuccess;
    }

    void printUserCart(User* user) {
        Cart& cart = user->getCart();
        if (cart.isEmpty()) {
            std::cout << "Cart is empty!" << std::endl;
            return;
        }
        std::cout << "Cart Contents:\n";
        for (const auto& product : cart.getProducts()) {
            std::cout << product.getName() << " (" << product.getPrice() << " PKR)\n";
        }
        std::cout << "Total: " << cart.getTotalCost() << " PKR" << std::endl;
    }
};

#endif