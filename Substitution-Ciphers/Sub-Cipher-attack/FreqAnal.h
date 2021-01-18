#include <fstream>
#include <map>
#include <cctype>
#include <algorithm>
#include "../Caesar-cipher-attack/FreqAnal.h"

class Sub_Cipher_Analsis: public Caesar_Analsis
{
    std::map<char,int>::iterator freqArr[1000];
    char freqChars[27] = {' ', 'E', 'T', 'A', '0', 'I', 'N', 'S', 'R', 'H', 'D', 'L', 'U', 'C', 'M', 'F', 'Y', 'W', 'G', 'P', 'B', 'V', 'K', 'X', 'Q', 'J', 'Z'};
    int charIdx =0;
public:
    const char* decryptCipher(int& count) {
        int i=0;
        while (highestFreq() != cipherText.end())
        {
            freqArr[i++] = highestFreq();
            cipherText.erase(highestFreq());
        }
        int shiftKey=0;
        if (count < 27) 
            shiftKey = freqArr[0]->first - freqChars[count];
        else {
            return handleFailure();
        }
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
            const int KeySpace = 93;
            const int Offset = 32;
            int sum = (a - key) % KeySpace + Offset;
            if (sum < (KeySpace + Offset) && sum > Offset)
                a = char((a - key) % KeySpace + Offset);
    }
};

