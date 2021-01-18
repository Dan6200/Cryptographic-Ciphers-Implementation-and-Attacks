#include "../Caesar-cipher/Caesar-Shift.h"

class Sub_Ciph: public Caesar
{
public:
    const char* getCipherText() {
        char* plaintext = getPlainText();
        int count = getCount();
        int i=0;
        const int KeySpace = 93;
        const int Offset = 32;
        const int Key = 17;
        for(; i < count; i++) 
        {   // Avoids negative values and other values that may cause the OS ascii handler to crash
            int sum = (plaintext[i] + Key) % KeySpace + Offset;
            if (sum < (Offset + KeySpace) && sum > Offset)
                plaintext[i]  = char(sum);
        }
        plaintext[i] = '\0';
        return (const char*) plaintext;
    }
};
