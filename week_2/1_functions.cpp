#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// DECLARING A FUNCTION
int addTwoNumbers(int x, int y);

// DEFINING A FUNCTION
int addTwoNumbers(int x, int y) {
    return x + y;
}

// OVERLOADING A FUNCTION
double addTwoNumbers(double x, double y) {
    return x + y;
}

// COPY BY VALUE EXAMPLE
void addTogether(int x, int y) {
    x += y;
}

// COPY BY REFERENCE
void addTogetherByReference(int& x, int& y) {
    x += y;
}

// STATIC VARIABLES WITHIN FUNCTION EXAMPLE
void staticAddTwoNumbers(int x, int y) {
    static bool calculated = false;
    static int lastCalculation;

    if (calculated) {
        std::cout << "Last calculation: " << lastCalculation << std::endl;
    }
    lastCalculation = x + y;
    std::cout << "New calculation: " << lastCalculation << std::endl;
    calculated = true;
}

// RECURSIVE FUNCTION
void countToNumber(int x) {
    static int goal = x;
    static int counter = 0;

    if (counter <= goal) {
        std::cout << counter << std::endl;
        counter++;
        countToNumber(goal);
    }
}

// FUNCTION THAT TAKES FUNCTION AS PARAMETER
void doCalculation(int x, int y, void (*callback)(int)) {
    callback(addTwoNumbers(x,y));
}

void doDivision(double x, double y, std::function<void(double)> callback ) {
    callback(x / y);
}

void writeResult(int value) {
    std::cout << "The result is: " << value << std::endl;
}

// KEEPING TRACK OF FUNCTION RESULT
int addStringsTogether(std::string& firstWord, std::string secondWord, int maxLength) {
    if ((firstWord.length() + secondWord.length()) > maxLength) {
        return 1;
    } else {
        firstWord.append(secondWord);
        return 0;
    }
}

int main(void) {
    int number1 = 3;
    int number2 = 22;
    double number3 = 3.2;
    double number4 = 2.5;
    std::vector<int> v = {5, 2, 9, 1};

    // WRITING OUT THE RESULT OF ADDING TWO INTEGERS
    std::cout << number1 << " + " << number2 << " = " << addTwoNumbers(number1, number2) << std::endl;

    // WRITING OUT THE RESULT OF ADDING TWO DOUBLES
    std::cout << number3 << " + " << number4 << " = " << addTwoNumbers(number3, number4) << std::endl;

    // TRYING TO ADD NUMBER2 TO NUMBER1
    addTogether(number1, number2); // What will the value be oft number1 after the function?
    std::cout << "Number 1 is now: " << number1 << std::endl;

    // COPY BY REFERENCE
    addTogetherByReference(number1, number2);
    std::cout << "Number 1 after addTogetherByReference: " << number1 << std::endl;

    // SHOWING THE USE STATIC KEYWORD
    staticAddTwoNumbers(20, 30);
    staticAddTwoNumbers(12, 32);

    // CALLING A RECURSIVE FUNCTION
    countToNumber(10);

    // USING A CALLBACK FUNCTION
    doCalculation(number1, number1, writeResult);

    // USING A LAMBDA FUNCTION TO SORT A VECTOR
    std::sort(v.begin(), v.end(), [](int a, int b) {
        return a < b;
    });

    for (auto number : v) {
        std::cout << number << std::endl;
    }

    // USING A LAMBDA FUNCTION TO ADD NUMBERS
    int number5 = [=]() {
        return number1 + number2;
    }();

    // DECLARING A LAMBDA FUNCTION
    auto localAdder = [](int x, int y) {
        return x + y;
    };
    int number6 = localAdder(number3, number4);
    std::cout << "Lambda localAdder result: " << number6 << std::endl;

    // PASSING LAMBDA FUNCTION AS A PARAMETER
    doCalculation(number1, number2, [](int value) {
        std::cout << "Lambda callback function value : " << value << std::endl; 
    });

    doDivision(number3, number4, [](double x) {
        std::cout << "Lambda callback division result: " << x << std::endl;
    });

    // TRACKING FUNCTION RESULT
    std::string firstName = "Kral";
    std::string lastName = "Morg";

    if (addStringsTogether(firstName, lastName, 8) == 0) {
        std::cout << "String concatenated properly" << std::endl;
        std::cout << "String: " << firstName << std::endl;
    } else {
        std::cout << "String concatination failed" << std::endl;
        std::cout << "String: " << firstName << std::endl;
    }

    return 0;
}