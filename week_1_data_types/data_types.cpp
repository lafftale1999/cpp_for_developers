#include <iostream>

int main (void) {

    // ---------------------------- CHARACTER -----------------------------------------------------------
    // Can contain either a number or a character. Will be implicitly casted to a character when used.
    char char_ex = 'H';                             // 1 Byte   -127 - 127 or 0 - 255
    unsigned char us_char = 'H';                    // 1 Byte   0 - 255
    signed s_char = 'H';  ;                         // 1 Byte   -127 - 127


    // ---------------------------- BOOL -----------------------------------------------------------------
    // Can only have two values, true or false.
    bool isTrue = true;
    bool isFalse = false;

    // ---------------------------- INTEGER --------------------------------------------------------------
    int int_ex = 1337;                              // 4 Bytes  -2147483648 to 2147483647
    unsigned int us_int = 1337;                     // 4 Bytes  0 to 4294967295
    signed int s__int = 1337;                       // 4 Bytes  -2147483648 to 2147483647


    // ---------------------------- SHORT INTEGER ---------------------------------------------------------
    short int short_int_ex = 1337;                  // 2bytes   -32768 to 32767
    unsigned short int us_short_int = 1337;         // 2bytes   0 to 65,535
    signed short int s_short_int = 1337;            // 2bytes	-32768 to 32767    


    // ---------------------------- LONG INTEGER ----------------------------------------------------------
    long int long_int_ex = 1337;                    // 8bytes	-9223372036854775808 to 9223372036854775807
    signed long int s_long_int = 1337;  	        // 8bytes	same as long int
    unsigned long int us_long_int = 1337;	        // 8bytes	0 to 18446744073709551615


    // ---------------------------- LONG LONG INTEGER -----------------------------------------------------
    long long int long_long_int = 1337;             // 8bytes	-(2^63) to (2^63)-1
    unsigned long long int us_long_long_int = 1337; // 8bytes	0 to 18,446,744,073,709,551,615
    

    // ---------------------------- DECIMAL VALUES --------------------------------------------------------
    float float_ex = 13.37f;                    	// 4 bytes	
    double double_ex = 13.37;                   	// 8bytes	
    long double f_double = 13.37;                   // 12bytes


    // ---------------------------- CHARACTER ARRAY -------------------------------------------------------
    // You need to assign the value of the array OR the size when declaring it.
    char *name = "Barl Chroman";                    // * is a pointer to the first character in the string
    char anotherName[] = "Rupert";                  // Declaring and assigning value

    char someName[5];                               // Declaring without assigning
    someName[0] = 'C';                              // Assigning values
    someName[1] = 'a';
    someName[2] = 'r';
    someName[3] = 'l';
    someName[4] = '\0';

    char *pointerToName = someName;                 // Creates a pointer to the first character in the string


    // ---------------------------- STRING ----------------------------------------------------------------
    std::string myString = "Hello World";           // Dynamic sizing allocated on the heap
    
    std::string anotherString;                      
    anotherString = "Hello World";

    return 0;
}