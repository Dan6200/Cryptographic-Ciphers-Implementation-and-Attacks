class Sub_Ciph: public Caeser() {

public:
    const char* getCipherText() {
        int i=0;
        for(; i < charCount; i++) 
            plaintext[i] = (!isalpha(plaintext[i])) ? plaintext[i] :
                char((plaintext[i] + 17) % 93 + 32);
        plaintext[i] = '\0';
        return (const char*) plaintext;
    }
};
