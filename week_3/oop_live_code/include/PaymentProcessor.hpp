#ifndef PAYMENT_PROCESSOR_HPP_
#define PAYMENT_PROCESSOR_HPP_

class PaymentProcessor {
public:
    virtual ~PaymentProcessor() = default;
    virtual bool processPayment(double amount, double balance) = 0;
};

class PaypalProcess : public PaymentProcessor {
public:
    bool processPayment(double amount, double balance) override;
};

class CashProcess : public PaymentProcessor {
public:
    bool processPayment(double amount, double balance) override;
};

class CardProcess : public PaymentProcessor {
public:
    bool processPayment(double amount, double balance) override;
};

#endif