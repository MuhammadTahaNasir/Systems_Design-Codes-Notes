#ifndef PAYMENT_STRATEGY_HPP
#define PAYMENT_STRATEGY_HPP

class PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() {}
};

#endif