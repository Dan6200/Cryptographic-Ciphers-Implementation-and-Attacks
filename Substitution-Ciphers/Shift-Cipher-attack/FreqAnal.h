#include <fstream>
#include "../Caesar-cipher-attack/FreqAnal.h"

class Shift_Cipher_Analsis: public Caesar_Analsis
{
    char freqChars[27] = {' ', 'E', 'T', 'A', '0', 'I', 'N', 'S', 'R', 'H', 'D', 'L', 'U', 'C', 'M', 'F', 'Y', 'W', 'G', 'P', 'B', 'V', 'K', 'X', 'Q', 'J', 'Z'};
    int charIdx =0;
    const int KeySpace = 93;
    const int Offset = 32;
public:
    const char* decryptCipher(int& count) {
        int shiftKey;
        if (count < 27) 
            shiftKey = getKey(highestFreq()->first, freqChars[count]);
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
            /* 
                key - k,
                KeySpace - p,
                Offset - C,
                plain text - x,
                cipher text - y.

                x = [(y - C) - k mod p] + C
            */
            int x, y = a;
            // Avoid decrypting unencrypted characters
            if (y < Offset || y > (Offset+KeySpace)) return;
            int diff = (y - Offset) - key;
            // mod p:
            if (diff < 0) diff += KeySpace;
            x = diff + Offset;
            a = char(x);
    }
};

