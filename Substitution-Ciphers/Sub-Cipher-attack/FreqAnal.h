#include <fstream>
#include <map>
#include <cctype>
#include <algorithm>
#include "../Caesar-cipher-attack/FreqAnal.h"

class Sub_Cipher_Analsis: public Caesar_Analsis
{
    std::map<char,int>::iterator freqArr[1000];
public:
    const char* decryptCipher(char commnLettr, int& count) {
        while (highestFreq() != cipherText.end())
        {
            freqArr[i++] = highestFreq();
            cipherText.erase(highestFreq());
        }
        int shiftKey = freqArr[count++]->first - commnLettr;
        // Erase element
        std::ifstream cipher;
        cipher.open("cipher-text.txt");
        char letter;
        int i = 0;
        while (cipher.get(letter))
        {
            shiftBy(letter, shiftKey);
            setDecryptText(letter, i);
            i++;
        }
        cipher.close();
        return getDecryptText();
   }

    void shiftBy(char& a, int key) {
            a = char((a - key) % 26 + 65);
    }
};

