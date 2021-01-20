#include <cstring>
#include <cctype>

class Caesar {
    char* plaintext;
    int charCount;
    const int C = 65;
    const int k = 23;
    const int m = 26;

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
        int x, y;
        /* y = [(x - C) + k mod p] + C, 
            offset - C = 'A'
            key - k = 23,
            keyspace - m = 26,
            x - plain text
            y - cipher text
        */
        for(; i < charCount; i++) 
        {
            x = plaintext[i];
            y = (!isalpha(x)) ? x : (((x - C) + k) % m) + C;
            plaintext[i] = char(y);
        }
        plaintext[i] = '\0';
        return (const char*) plaintext;
    }
};
