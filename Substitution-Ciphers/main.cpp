#include <iostream>
#include "Caesar-Shift.h"

int main() {
    char usrInput[10000];
    Caesar cipher;
    std::cout << "Enter text to be encrypted (to quit enter \"|\" character):\n\n";
    std::cin.get(usrInput, 10000, '|');
    std::cout << '\n';
    cipher.setPlainText((const char*) usrInput);
    std::cout << cipher.getCipherText() << '\n' << std::endl;
}


