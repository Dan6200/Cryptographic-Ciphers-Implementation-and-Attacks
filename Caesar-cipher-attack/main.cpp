#include "FreqAnal.h"
#include <iostream>
#include <cstring>

int main() {
    LetterFreq cipher;
    std::cout << "Save cipher text in this directory, under the name \"cipher-text.txt\", \nRepeatedly decrypt to retrieve plaintext. Best case scenario, it takes less than 26 tries" << std::endl;
    int count = 0;
    char quit = false;
    while (count < 26 && !quit) {
        std::cout << "Attempt " << count+1 << std::endl;
        const char* plaintext = cipher.decryptCipher();
        if (!strcmp(plaintext,"TERMINATE"))
            break;
        std::cout << plaintext << '\n' << std::endl;
        std::cout << "Quit decryption?(press \"Y\" to quit)\n";
        char res;
        std::cin >> res;
        if (toupper(res) == 'Y')
            quit = true;
        else quit = false;
        
        count++;
    }
    if (count == 26) {
        std::cout << "Could not decrypt text" << std::endl;
    }
}
