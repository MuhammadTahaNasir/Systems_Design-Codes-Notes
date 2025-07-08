#ifndef JAZZCASH_PAYMENT_HPP
#define JAZZCASH_PAYMENT_HPP

#include <string>
#include "PaymentStrategy.hpp"

class JazzCashPayment : public PaymentStrategy {
private:
    std::string mobileNumber;

public:
    JazzCashPayment(std::string mobileNumber) : mobileNumber(mobileNumber) {}

    void pay(double amount) override {
        std::cout << "Paid " << amount << " PKR using JazzCash with mobile " << mobileNumber << std::endl;
    }
};

#endif