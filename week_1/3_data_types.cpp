#include <iostream>

int main (void) {
    // ---------------------------- DECLARATION & INITIALIZATION ---------------------------------------
    int x;          // Declaration   
    x = 20;         // Initialization

    int y = 30;     // Both


    // ---------------------------- CHARACTER -----------------------------------------------------------
    // Can contain either a number or a character. Will be implicitly casted to a character when used.
    char regularChar = 'H';                             // 1 Byte   -127 - 127 or 0 - 255
    unsigned char unsignedChar = 'H';                   // 1 Byte   0 - 255
    signed signedChar = 'H';  ;                         // 1 Byte   -127 - 127

    char charAsNumber = 34;                             // Will be implicitly casted as a character when printing.


    // ---------------------------- BOOL -----------------------------------------------------------------
    // Can only have two values, true or false.
    bool isTrue = true;                                 // 1 Byte
    bool isFalse = false;                               // 1 Byte


    // ---------------------------- INTEGER --------------------------------------------------------------
    int regularInt = 1337;                              // 2 or 4 Bytes  -2147483648 to 2147483647
    unsigned int unsignedInt = 1337;                    // 2 or 4 Bytes  0 to 4294967295
    signed int signedInt = 1337;                        // 2 or 4 Bytes  -2147483648 to 2147483647


    // ---------------------------- SHORT INTEGER ---------------------------------------------------------
    short int shortInt = 1337;                          // 2 Bytes   -32768 to 32767
    unsigned short int unsignedShortInt = 1337;         // 2 Bytes   0 to 65,535
    signed short int signedShortInt = 1337;             // 2 Bytes	-32768 to 32767    


    // ---------------------------- LONG INTEGER ----------------------------------------------------------
    long int longInt = 1337;                            // 4 or 8 Bytes	-9223372036854775808 to 9223372036854775807
    unsigned long int unsignedLongInt = 1337;           // 4 or 8 Bytes	0 to 18446744073709551615
    signed long int signedLongInt = 1337;  	            // 4 or 8 Bytes	same as long int
    	        


    // ---------------------------- LONG LONG INTEGER -----------------------------------------------------
    long long int longLongInt = 1337;                   // 8 Bytes	-(2^63) to (2^63)-1
    unsigned long long int unsignedLongLongInt = 1337;  // 8 Bytes	0 to 18,446,744,073,709,551,615
    

    // ---------------------------- DECIMAL VALUES --------------------------------------------------------
    float regularFloat = 13.37f;                    	// 4 Bytes	
    double regularDouble = 13.37;                       // 8 Bytes	
    long double longDouble = 13.37;                     // 12 Bytes


    // ---------------------------- EXPLICIT CASTING ------------------------------------------------------
    /* 
    Casting from a larger type (double) to a smaller type (int) can cause data loss.
    In this case, we lose the fractional part of the number.
    Note: it’s not really about “losing 4 bytes of data,” but about losing information
    that cannot fit into the target type.
    */
    double aNumber = 3.14159265359;                     
    int aNumberCasted = (int) aNumber;

    /* 
    Casting from a smaller type (int) to a larger type (long long int) is safe,
    because the larger type can fully represent the value of the smaller one.
    No information is lost in this direction.
    */
    int anotherNumber = 323932012;
    long long int anotherNumberCasted = (long long int) anotherNumber;


    // -------------------------- CONST -------------------------------------------------------------------
    const int constInteger = 32;


    // -------------------------------- MACROS ------------------------------------------------------------
    
    #define PI 3.14159
    #define SQUARE(x) ((x) * (x))

    double piSquared = SQUARE(PI);
    
    return 0;
}