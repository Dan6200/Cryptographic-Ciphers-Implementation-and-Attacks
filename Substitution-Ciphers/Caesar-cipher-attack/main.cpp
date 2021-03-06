#include "FreqAnal.h"
#include <iostream>
#include <cstring>

int main() {
    Caesar_Analsis attack;
    std::cout << "Save attack text in this directory, under the name \"attack-text.txt\", \nRepeatedly decrypt to retrieve plaintext. Best case scenario, it takes less than 26 tries" << std::endl;
    int count = 0;
    char quit = false;
    while (count < 26 && !quit) {
        std::cout << "Attempt " << count+1 << std::endl;
        const char* plaintext = attack.decryptCipher('E');
        if (!strcmp(plaintext,"TERMINATE"))
        {
            count = 26;
            break;
        }
        std::cout << plaintext << '\n' << std::endl;
        std::cout << "Quit decryption? Quit if successful(press \"q\" to quit, any other key to continue)\n";
        char res;
        std::cin.get(res);
        if (toupper(res) == 'Q')
            quit = true;
        else quit = false;
        
        count++;
    }
    if (count == 26) {
        std::cout << "\nCould not decrypt text\n" << std::endl;
    }
    else {
        std::cout << "\nSuccessfully decrypted!\n" << std::endl;
        if (count <= 1)
            std::cout << "Cipher text is not very secure\n" << std::endl;
    }
}
