class LetterFreq {
    char mostFreqLetters [] = {
        'E', 'T', 'A', 'O', 'I', 'N', 'S', 'R', 'H', 'D', 'L', 'U', 'C', 'M', 'F', 'Y', 'W',
        'G', 'P', 'B', 'V', 'K', 'X', 'Q', 'J', 'Z'};
    
    int inputSize;

    void parseCipher() {}

    struct Cipher {
        char text[100000];
        int frequency[100000];
        void sort() {}
        void shiftBy() {}
    }

public:
    const char* decryptCipher(int idx) {
       Cipher cipher;
       cipher.sort();
       int shiftKey = cipher.freqLetters[idx] - 'E';
       cipher.shiftBy(shiftKey);
       return static_cast<const char*>(cipher.text);
    }
};

