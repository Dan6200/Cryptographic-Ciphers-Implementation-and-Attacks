#include <cstring>
#include <cctype>

class Caesar {
    char* plaintext;
    int charCount;

public:
    Caesar(): plaintext(new char[100000]) {}

    void setPlainText(const char* text) {
        int i=0;
        for(; i < (int)strlen(text); i++)
            plaintext[i] = toupper(text[i]);
        charCount=i;
    }

    char* getPlainText() { return plaintext; }

    int getCount() { return charCount; }

    const char* getCipherText() {
        int i=0;
        int C = 65;
        int k = 23;
        int p = 26;
        int x, y;
        /* y = [(x - C) + k mod p] + C], C = 'A' */
        for(; i < charCount; i++) 
        {
            x = plaintext[i];
            y = (!isalpha(x)) ? x : (((x - C) + k) % p) + C;
            plaintext[i] = char(y);
        }
        plaintext[i] = '\0';
        return (const char*) plaintext;
    }
};
