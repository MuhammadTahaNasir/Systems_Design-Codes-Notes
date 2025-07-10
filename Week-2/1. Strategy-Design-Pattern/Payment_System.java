interface PaymentStrategy {
    void pay(double amount);
}

class CardPayment implements PaymentStrategy {
    @Override
    public void pay(double amount) {
        System.out.println("Paid " + amount + " via Credit/Debit Card");
    }
}

class NetBankingPayment implements PaymentStrategy {
    @Override
    public void pay(double amount) {
        System.out.println("Paid " + amount + " via Net Banking");
    }
}

class JazzCashPayment implements PaymentStrategy {
    @Override
    public void pay(double amount) {
        System.out.println("Paid " + amount + " via JazzCash Mobile");
    }
}

class PaymentSystem {
    private PaymentStrategy paymentStrategy;

    public PaymentSystem(PaymentStrategy paymentStrategy) {
        this.paymentStrategy = paymentStrategy;
    }

    public void payNow(double amount) {
        paymentStrategy.pay(amount);
    }
}

public class Main {
    public static void main(String[] args) {
        PaymentSystem jazzCashPayment = new PaymentSystem(new JazzCashPayment());
        jazzCashPayment.payNow(100.0);

        PaymentSystem cardPayment = new PaymentSystem(new CardPayment());
        cardPayment.payNow(200.0);
    }
}