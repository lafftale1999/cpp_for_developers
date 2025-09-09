#include <iostream>

/* 
    Create a program that receives a certain amount of SEK and then sorts it into bills and coins.
    Maximize so you sort by highes value and descending. For example:
    346 SEK:
    1000-note: 0 pcs
    500-note: 0 pcs
    200-note: 1 pcs
    100-note: 1 pcs
    50-note: 0 pcs
    20-note: 2 pcs 
    10-coin: 2pcs         
    5-coin: 1 pcs
    2-coin: 0 pcs
    1-coin: 1 pcs
*/

int main(void) {
    
    enum Currency{
        THOUSAND = 1000,
        FIVE_HUNDRED = 500,
        TWO_HUNDRED = 200,
        HUNDRED = 100,
        FIFTY = 50,
        TWENTY = 20,
        TEN = 10,
        FIVE = 5,
        TWO = 2,
        ONE = 1
    };
    
    struct CashRegister {
        int thousandNotes;
        int fiveHundredNotes;
        int twoHundredNotes;
        int hundredNotes;
        int fiftyNotes;
        int twentyNotes;
        int tenCoin;
        int fiveCoin;
        int twoCoin;
        int oneCoin;
    };

    int userEnteredAmount = 0;
    int userOriginalEnteredAmount;

    std::cout << "Enter the amount to count: ";
    std::cin >> userEnteredAmount;

    // save the original state
    userOriginalEnteredAmount = userEnteredAmount;

    // create cashregister
    CashRegister cashRegister;

    // sort 1000
    cashRegister.thousandNotes = userEnteredAmount / THOUSAND;
    userEnteredAmount -= cashRegister.thousandNotes * THOUSAND;

    // sort 500
    cashRegister.fiveHundredNotes = userEnteredAmount / FIVE_HUNDRED;
    userEnteredAmount -= cashRegister.fiveHundredNotes * FIVE_HUNDRED;

    // sort 200
    cashRegister.twoHundredNotes = userEnteredAmount / TWO_HUNDRED;
    userEnteredAmount -= cashRegister.twoHundredNotes * TWO_HUNDRED;

    // sort 100
    cashRegister.hundredNotes = userEnteredAmount / HUNDRED;
    userEnteredAmount -= cashRegister.hundredNotes * HUNDRED;

    // sort 50
    cashRegister.fiftyNotes = userEnteredAmount / FIFTY;
    userEnteredAmount -= cashRegister.fiftyNotes * FIFTY;

    // sort 20
    cashRegister.twentyNotes = userEnteredAmount / TWENTY;
    userEnteredAmount -= cashRegister.twentyNotes * TWENTY;

    // sort 10
    cashRegister.tenCoin = userEnteredAmount / TEN;
    userEnteredAmount -= cashRegister.tenCoin * TEN;

    // sort 5
    cashRegister.fiveCoin = userEnteredAmount / FIVE;
    userEnteredAmount -= cashRegister.fiveCoin * FIVE;

    // sort 2
    cashRegister.twoCoin = userEnteredAmount / TWO;
    userEnteredAmount -= cashRegister.twoCoin * TWO;

    // sort 1
    cashRegister.oneCoin = userEnteredAmount / ONE;
    userEnteredAmount -= cashRegister.oneCoin * ONE;

    // Print the results
    std::cout << userOriginalEnteredAmount << " in sorted currency:" << std::endl;
    std::cout << "1000:\t" << cashRegister.thousandNotes << " pcs" << std::endl;
    std::cout << "500:\t" << cashRegister.fiveHundredNotes << " pcs" << std::endl;
    std::cout << "200:\t" << cashRegister.twoHundredNotes << " pcs" << std::endl;
    std::cout << "100:\t" << cashRegister.hundredNotes << " pcs" << std::endl;
    std::cout << "50:\t\t" << cashRegister.fiftyNotes << " pcs" << std::endl;
    std::cout << "20:\t\t" << cashRegister.twentyNotes << " pcs" << std::endl;
    std::cout << "10:\t\t" << cashRegister.tenCoin << " pcs" << std::endl;
    std::cout << "5:\t\t" << cashRegister.fiveCoin << " pcs" << std::endl;
    std::cout << "2:\t\t" << cashRegister.twoCoin << " pcs" << std::endl;
    std::cout << "1:\t\t" << cashRegister.oneCoin << " pcs" << std::endl;
}