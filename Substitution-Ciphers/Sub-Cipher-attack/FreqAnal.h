#include <fstream>
#include <map>
#include <cctype>
#include <algorithm>
#include "../Caesar-cipher-attack/FreqAnal.h"

class Sub_Cipher_Analsis: public Caesar_Analsis
{
    char freqChars[27] = {' ', 'E', 'T', 'A', '0', 'I', 'N', 'S', 'R', 'H', 'D', 'L', 'U', 'C', 'M', 'F', 'Y', 'W', 'G', 'P', 'B', 'V', 'K', 'X', 'Q', 'J', 'Z'};
    int charIdx =0;
    const int KeySpace = 93;
    const int Offset = 32;
public:
    const char* decryptCipher(int& count) {
        int shiftKey;
        if (count < 27) 
            shiftKey = (highestFreq()->first - freqChars[count]) % KeySpace + Offset;
        else {
            return handleFailure();
        }
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
            int sum = (a - key) % KeySpace + Offset;
            if (sum <= (KeySpace + Offset) && sum >= Offset)
                a = char(sum);
    }
};

