#include <iostream>

int main(void) {

    // ----------------------- DECLARING AND/OR INIT -----------------------
    std::string firstString = "The first string";
    std::string secondString = ("The second string");
    
    std::string thirdString;
    thirdString = "The third string";

    std::string fourthString = thirdString;
    thirdString = "Hello World";

    // What will be printed to console?
    std::cout << fourthString << std::endl;

    
    // ----------------------- USEFUL METHODS FOR STRINGS -----------------------
    // .length() and .size() - both will return the length of the string.
    std::string stringExample = "Example string";
    std::cout << stringExample.length() << std::endl;       // Check the length of string
    std::cout << stringExample.size() << std::endl;         // check the size of the string


    // .append() and +
    stringExample.append(" is now longer");                 // Adds the string in parameter to the called string
    stringExample += firstString;                           // Adds firstString to the back of stringExample
    std::cout << stringExample << std::endl;

    std::string anotherString = stringExample + " " + firstString;

    // accessing elements in string [] and .at()
    std::cout << stringExample[2] << " is the same as " << stringExample.at(2) << std::endl;


    // comparing strings with == and .compare()
    // this will return either true or false depending if they are equal
    bool isEqual = (stringExample == firstString);

    // this will return -1 if stringExample is alphabetically before firstString,
    // 0 if they are equal or 1 if stringExample is alphabetically after firstString.
    int indexEqual = stringExample.compare(firstString);


    // Extracting characters using .substr()
    std::string helloString = thirdString.substr(0,4);
    std::cout << helloString << std::endl;


    // Searching in a string with .find()
    // This will return the index of the first appearance of the substring
    int position = stringExample.find("is now longer");


    // Modifying strings
    helloString.replace(0, helloString.length(), "Bonjour");
    helloString.erase(0, helloString.length());
    helloString.insert(0, "Hola");
    helloString.empty();
    
    return 0;
}