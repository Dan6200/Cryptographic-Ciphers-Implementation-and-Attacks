#include <cstring>

class Caesar {
    char* plaintext;
    int charCount;

public:
    void setPlainText(const char* text) {
        int i=0;
        for(; i < strlen(text); i++)
            plaintext[i] = text[i];
        charCount=i;
    }

    const char* getCipherText() {
        i=0;
        for(; i < charCount; i++) 
            plaintext[i] = char((plaintext[i] + 23) % 26);
        plaintext[i] = '\0';
        return (const char*) plaintext;
    }
}
             

