#include <iostream>
#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Owner.hpp"
#include "include/PaymentProcessor.hpp"

#include <vector>

int main(void) {

    PaypalProcess paypal;
    CardProcess card;
    CashProcess cash;

    std::vector<PaymentProcessor*> paymentExamples = {&paypal, &card, &cash};

    double cartTotalAmount = 2300;
    double userBalance = 5000;

    int userInput = 0;

    paymentExamples.at(userInput)->processPayment(cartTotalAmount, userBalance);

    return 0;
}