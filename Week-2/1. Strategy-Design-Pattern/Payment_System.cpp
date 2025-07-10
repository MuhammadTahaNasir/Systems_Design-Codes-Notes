#include <iostream>
#include <string>

using namespace std;

// Abstract base class
class PaymentStrategy
{
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() {} // Virtual destructor for proper cleanup
};

// Concrete strategy: CardPayment
class CardPayment : public PaymentStrategy
{
public:
    void pay(double amount) override
    {
        cout << "Paid " << amount << " via Credit/Debit Card" << endl;
    }
};

// Concrete strategy: NetBankingPayment
class NetBankingPayment : public PaymentStrategy
{
public:
    void pay(double amount) override
    {
        cout << "Paid " << amount << " via Net Banking" << endl;
    }
};

// Concrete strategy: JazzCashPayment 
class JazzCashPayment : public PaymentStrategy
{
public:
    void pay(double amount) override
    {
        cout << "Paid " << amount << " via JazzCash Mobile" << endl;
    }
};

// Context class that uses the strategy
class PaymentSystem
{
private:
    PaymentStrategy *paymentStrategy;

public:
    PaymentSystem(PaymentStrategy *strategy) : paymentStrategy(strategy) {}

    void payNow(double amount)
    {
        paymentStrategy->pay(amount);
    }

    ~PaymentSystem()
    {
        delete paymentStrategy; // Clean up the strategy object
    }
};

int main()
{
    PaymentSystem *jazzCashPayment = new PaymentSystem(new JazzCashPayment());
    jazzCashPayment->payNow(100.0);

    PaymentSystem *cardPayment = new PaymentSystem(new CardPayment());
    cardPayment->payNow(200.0);

    delete jazzCashPayment;
    delete cardPayment;
    return 0;
}