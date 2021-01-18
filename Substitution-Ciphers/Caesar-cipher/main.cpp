#include <iostream>
#include <fstream>
#include "Caesar-Shift.h"

int main() {
    char usrInput[100000];
    std::ofstream output;
    output.open("cipher-text.txt");
    Caesar cipher;
    std::cout << "Enter text to be encrypted (to quit enter \"|\" character):\n\n";
    std::cin.get(usrInput, 100000, '|');
    std::cout << '\n';
    cipher.setPlainText((const char*) usrInput);
    const char* plaintext = cipher.getCipherText();
    std::cout << plaintext << '\n' << std::endl;
    std::cout << "Ciphertext generates an output file, \"cipher-text.txt\". Copy it to the Caesar-cipher-attack directory to decrypt\n" << std::endl;
    output << plaintext << std::endl;
}


