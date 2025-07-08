#ifndef SELLER_MANAGER_HPP
#define SELLER_MANAGER_HPP

#include <vector>
#include <string>
#include "models/Seller.hpp"

class SellerManager {
private:
    static SellerManager* instance;
    std::vector<Seller> sellers;
    SellerManager() {}

public:
    static SellerManager* getInstance() {
        if (!instance) instance = new SellerManager();
        return instance;
    }

    void addSeller(Seller seller) {
        sellers.push_back(seller);
    }

    std::vector<Seller> searchByLocation(std::string location) {
        std::vector<Seller> result;
        for (const auto& seller : sellers) {
            if (seller.getAddress().find(location) != std::string::npos) {
                result.push_back(seller);
            }
        }
        return result;
    }

    std::vector<Seller> searchByCategory(std::string category) {
        std::vector<Seller> result;
        for (const auto& seller : sellers) {
            for (const auto& product : seller.getProducts()) {
                if (product.getCategory() == category) {
                    result.push_back(seller);
                    break;
                }
            }
        }
        return result;
    }
};

SellerManager* SellerManager::instance = nullptr;

#endif