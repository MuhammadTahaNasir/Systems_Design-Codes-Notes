#ifndef CREDIT_CARD_PAYMENT_HPP
#define CREDIT_CARD_PAYMENT_HPP

#include <string>
#include "PaymentStrategy.hpp"

class CreditCardPayment : public PaymentStrategy {
private:
    std::string cardNumber;

public:
    CreditCardPayment(std::string cardNumber) : cardNumber(cardNumber) {}

    void pay(double amount) override {
        std::cout << "Paid " << amount << " PKR using Credit Card " << cardNumber << std::endl;
    }
};

#endif