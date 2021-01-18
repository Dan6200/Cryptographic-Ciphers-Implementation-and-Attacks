#include "../Caesar-cipher/Caesar-Shift.h"

class Sub_Ciph: public Caesar
{
public:
    const char* getCipherText() {
        char* plaintext = getPlainText();
        int count = getCount();
        int i=0;
        for(; i < count; i++) 
            plaintext[i] = char((plaintext[i] + 17) % 26 + 65);
        plaintext[i] = '\0';
        return (const char*) plaintext;
    }
};
