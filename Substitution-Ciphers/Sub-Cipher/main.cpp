#include <iostream>
#include <fstream>
#include "Sub-Cipher.h"

int main() {
    char usrInput[10000];
    std::ofstream output;
    output.open("cipher-text.txt");
    Sub_Ciph cipher;
    std::cout << "This cipher is more secure than the Caesar-cipher, (not that secure, if you are clever)\nEnter text to be encrypted (to quit enter \"|\" character):\n\n";
    std::cin.get(usrInput, 10000, '|');
    std::cout << '\n';
    cipher.setPlainText((const char*) usrInput);
    const char* plaintext = cipher.getCipherText();
    std::cout << plaintext << '\n' << std::endl;
    std::cout << "Ciphertext generates an output file, \"cipher-text.txt\". Copy it to the Sub-cipher-attack directory to decrypt\n" << std::endl;
    output << plaintext << std::endl;
}


