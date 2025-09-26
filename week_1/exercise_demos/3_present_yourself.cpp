#include <iostream>

/* 
    Create a program to present yourself. Receive your name, age, address, phone number and email through the console
    and then write it out back in console.
*/

int main(void) {

    std::string userName, userAddress, userPhone, userEmail;
    int userAge;

    std::cout << "What is your name? ";
    std::cin >> userName;

    std::cout << "How old are you?";
    std::cin >> userAge;

    std::cout << "What is your address?";
    std::cin >> userAddress;

    std::cout << "What is your phone number?";
    std::cin >> userPhone;

    std::cout << "What is your email?";
    std::cin >> userEmail;

    std::cout << "---------- USER INFORMATION ---------------" << std::endl;
    std::cout << "Name: " << userName << std::endl;
    std::cout << "Age: " << userAge << std::endl;
    std::cout << "Address: " << userAddress << std::endl;
    std::cout << "Phone: " << userPhone << std::endl;
    std::cout << "Email: " << userEmail << std::endl;
    
    return 0;
}