#include "../Caesar-cipher/Caesar-Shift.h"

class Sub_Ciph: public Caesar
{
    const int KeySpace = 93;
    const int Offset = 32;
    const int Key = 17;

public:
    const char* getCipherText() {
        char* plaintext = getPlainText();
        int count = getCount();
        int i=0;
        /* y = [(x - C) + k mod p] + C, 
            Offset = C =  ' '
            Key = k = 17,
            KeySpace = p = 26.
            x = plain text,
            y = cipher text.
        */
        for(; i < count; i++) 
        {   
            int x, y;
            x = plaintext[i];
            y = (((x - Offset) + Key) % KeySpace) + Offset;
            plaintext[i]  = char(y);
        }
        plaintext[i] = '\0';
        return (const char*) plaintext;
    }
};
