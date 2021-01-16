#include <cstring>
#include <cctype>

class Caesar {
    char* plaintext;
    int charCount;

public:
    Caesar(): plaintext(new char[100]) {}

    void setPlainText(const char* text) {
        int i=0;
        for(; i < strlen(text); i++)
            plaintext[i] = toupper(text[i]);
        charCount=i;
    }

    const char* getCipherText() {
        int i=0;
        for(; i < charCount; i++) 
            plaintext[i] = (plaintext[i] == ' ') ? plaintext[i] :
                char((plaintext[i] + 23) % 26 + 65);
        plaintext[i] = '\0';
        return (const char*) plaintext;
    }
};
