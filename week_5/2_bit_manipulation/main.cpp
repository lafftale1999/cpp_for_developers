#include <iostream>
#include <bitset>

void printResult(unsigned char bin1, unsigned char bin2, unsigned char result) {
    std::cout << "bin1:\t" << std::bitset<8>(bin1) << std::endl;
    std::cout << "bin2:\t" << std::bitset<8>(bin2) << std::endl;
    std::cout << "result:\t" << std::bitset<8>(result) << std::endl;
    std::cout << '\n';
}

int main(void) {

    unsigned char bin1 = 0b00010001;
    unsigned char bin2 = 0b01010000;
    unsigned char result = 0b0;

    // USING THE | OR-OPERATOR
    // one of the two comparing bits need to be 1 for result to be 1
    std::cout << "USING THE OR-OPERATOR\n";
    result = bin1 | bin2;
    printResult(bin1, bin2, result);

    // USING THE & AND-OPERATOR
    // both of the two comparing bits need to be 1 for result to be 1
    std::cout << "USING THE AND-OPERATOR\n";
    result = bin1 & bin2;
    printResult(bin1, bin2, result);

    // USING THE ^ XOR-OPERATOR
    // comparing bits need to be different to return 1, otherwhise 0
    std::cout << "USING THE XOR-OPERATOR\n";
    result = bin1 ^ bin2;
    printResult(bin1, bin2, result);

    // USING THE ~ NOT-OPERATOR
    // Negates the result, turning 1 to 0 and 0 to 1
    std::cout << "USING THE ~ NOT-OPERATOR\n";
    std::cout << "result:\t" << std::bitset<8>(result) << std::endl;
    result = result ^ result;
    std::cout << "result:\t" << std::bitset<8>(result) << std::endl;

    return 0;
}