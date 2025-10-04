#include <iostream>
#include <vector>

class HugeClass {
public:
    std::string name;
    std::string sound;
    std::string smell;
    std::string taste;
    std::string feeling;

    HugeClass(std::string n, 
        std::string s, 
        std::string sm,
        std::string t, 
        std::string f)
        : name(n), sound(s), smell(sm), taste(t), feeling(f)
        {}

    void print() {
        std::cout
            << name << std::endl
            << sound << std::endl
            << smell << std::endl
            << taste << std::endl
            << feeling << std::endl;
    }
};

void printHugeClass(HugeClass hc) {
    hc.print();
}

void printHugeClass(HugeClass* hc) {
    hc->print();
}

int main(void) {

    HugeClass hc = HugeClass("Carl", 
        "Loud", 
        "Margiela", 
        "Cinnamon", 
        "Smooth");
    
    printHugeClass(hc);
    printHugeClass(&hc);

    int age = 29;
    int* pAge = &age;

    std::cout << *pAge << '\n';

    return 0;
}


