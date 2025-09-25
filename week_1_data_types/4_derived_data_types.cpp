#include <iostream>

// -------------------------------- FUNCTION ---------------------------------------------------
// Return value | Function name | (parameters) { BODY OF CODE}
char getStudentGrade(int studenId) {
    // BODY OF CODE
}

int main(void) {

    // ---------------------------- ARRAY -------------------------------------------------------
    // You need to assign the value of the array OR the size when declaring it.    
    char *name = "Carl";                            // * is a pointer to the first character in the string
    
    char anotherName[] = "Carl";                    // Declaring and assigning value

    char someName[5];                               // Declaring without assigning
    someName[0] = 'C';                              // Assigning values
    someName[1] = 'a';
    someName[2] = 'r';
    someName[3] = 'l';
    someName[4] = '\0';

    // To calculate the length you divide the memory size of the array with the size of the first element in the array
    short int someNameLen = sizeof(someName) / sizeof(someName[0]);

    char *pointerToName = someName;                 // Creates a pointer to the first character in the string


    // ---------------------------- POINTER & REFERENCES ------------------------------------------
    int x = 23;

    int *pointerToX = &x;       // pointer to X
    int &referenceToX = x;      // reference to x

    x = 32;

    std::cout << *pointerToX << std::endl;
    std::cout << referenceToX << std::endl;

    return 0;
}