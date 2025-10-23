#include "../include/PaymentProcessor.hpp"

#include <iostream>

/* bool PaymentProcessor::processPayment(double amount, double balance) {
    std::cout << "Payment processor!" << std::endl;
    return false;
} */

bool PaypalProcess::processPayment(double amount, double balance) {
    if (amount <= balance) {
        std::cout << "Paypal payment successful!" << std::endl;
        return true;
    }

    return false;
}

bool CardProcess::processPayment(double amount, double balance) {
    if (amount <= balance) {
        std::cout << "Card payment successful!" << std::endl;
        return true;
    }

    return false;
}

bool CashProcess::processPayment(double amount, double balance) {
    if (amount <= balance) {
        std::cout << "Cash payment successful!" << std::endl;
        return true;
    }

    return false;
}