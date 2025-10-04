#include <iostream>

class PaymentProcessor {
public:
    virtual ~PaymentProcessor() {}
    virtual bool process(double amount) = 0;
};

class CreditCardProcessor : public PaymentProcessor {
public:
    bool process(double amount) override {
        // talk to credit card gateway
        return true;
    }
};

class PayPalProcessor : public PaymentProcessor {
public:
    bool process(double amount) override {
        // use PayPal API
        return true;
    }
};

class CryptoProcessor : public PaymentProcessor {
public:
    bool process(double amount) override {
        // crypto transfer
        return true;
    }
};

void checkout(PaymentProcessor& processor, double amount) {
    if (processor.process(amount)) {
        std::cout << "Payment successful\n";
    } else {
        std::cout << "Payment failed\n";
    }
}

int main(void) {

    PaymentProcessor* p = new CreditCardProcessor();

    p->process(2500);

    delete(p);

    return 0;
}