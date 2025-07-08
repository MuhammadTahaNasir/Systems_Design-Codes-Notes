#ifndef USER_HPP
#define USER_HPP

#include <string>
#include "Cart.hpp"

class User {
private:
    std::string userId;
    std::string name;
    std::string address;
    Cart cart;

public:
    User(std::string userId, std::string name, std::string address)
        : userId(userId), name(name), address(address), cart() {}

    std::string getId() const { return userId; }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    Cart& getCart() { return cart; }
};

#endif