#include <iostream>

int main(void) {

    // ---------------------------- STRUCTURES ---------------------------------------
    struct Student {
        char name[20];
        short int age;
        char grade;
    };

    Student student = {
        {"Ada Lovelace"},
        25,
        'A'
    };
    
    std::cout << "Name: " << student.name << std::endl;
    std::cout << "Age: " << student.age << std::endl;
    std::cout << "Grade: " << student.grade << std::endl;

    // ---------------------------- ENUMERATION ---------------------------------------
    enum AuthenticationType {
        RFID,
        PIN,
        RETINA 
    };

    AuthenticationType type = RFID;


    // ---------------------------- UNIONS --------------------------------------------
    struct Authentication {
        AuthenticationType type;

        union {
            char biometricHash[65];
            char pinCode[5];
            char keyID[10];
        };
    };

    Authentication auth;
    auth.type = RFID;
    snprintf(auth.keyID, sizeof(auth.keyID), "3E 54 9F");

    if(auth.type == RFID) {
        std::cout << auth.keyID << std::endl;
    }


    // ---------------------------- TYPEDEFINITION -------------------------------------
    typedef char Name[20];

    Name name = "Carl";


    // ---------------------------- USING ----------------------------------------------
    using uint = unsigned int;

    uint unsignedInteger = 54320;

    return 0;
}