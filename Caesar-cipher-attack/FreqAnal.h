#include <ifstream>
#include <map>
#include <algorithm>

class LetterFreq {
    char mostFreqLetters [] = {
        'E', 'T', 'A', 'O', 'I', 'N', 'S', 'R', 'H', 'D', 'L', 'U', 'C', 'M', 'F', 'Y', 'W',
        'G', 'P', 'B', 'V', 'K', 'X', 'Q', 'J', 'Z'};
    
    int inputSize;

    std::map<char,int> cipherText;
    
    void shiftBy() {
        for_
    }

    void parseCipher() 
    {
        ifstream cipher;
        cipher.open("cipher-text.txt");
        char letter;
        while (cipher.get(letter)) {
            if (cipherText.find(letter) == cipherText.end())
                cipherText[letter] = 1;
            else cipherText[letter]++;
        }

        cipher.close();
    }

    
    

public:
    const char* decryptCipher(int idx) {
       parseCipher();
       int shiftKey = highestFreq(cipherText) - 'E';
       cipher.shiftBy(shiftKey);
       return static_cast<const char*>(cipher.text);
    }
};

