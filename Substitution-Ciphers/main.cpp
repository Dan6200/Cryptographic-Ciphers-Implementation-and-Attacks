#include <iostream>
#include "Caesar-Shift.h"

int main() {
    char usrInput[100];
    Caesar cipher;
    std::cout << "Enter text to be encrypted:\n";
    std::cin.get(usrInput, 100, '\n');
    cipher.setPlainText((const char*) usrInput);
    std::cout << cipher.getCipherText() << std::endl;
}


