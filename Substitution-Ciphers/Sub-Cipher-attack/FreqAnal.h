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
        int i=0;
        while (highestFreq() != cipherText.end())
        {
            freqArr[i++] = highestFreq();
            cipherText.erase(highestFreq());
        }
        int shiftKey=0;
        if (count < 26) 
            int shiftKey = freqArr[count++]->first - commnLettr;
        else return handleFailure();
        std::ifstream cipher;
        cipher.open("cipher-text.txt");
        char letter;
        i = 0;
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
            const int KeySpace = 26;
            const int Offset = 65;
            int sum = (a - key) % KeySpace + Offset;
            if (sum < (KeySpace + Offset) && sum > Offset)
                a = char((a - key) % KeySpace + Offset);
    }
};

