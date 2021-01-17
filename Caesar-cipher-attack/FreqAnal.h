#include <fstream>
#include <map>
#include <cctype>
#include <algorithm>

class LetterFreq {
    char [] FAILURE = "TERMINATE";
    char mostFreqLetters [26] = {
        'E', 'T', 'A', 'O', 'I', 'N', 'S', 'R', 'H', 'D', 'L', 'U', 'C', 'M', 'F', 'Y', 'W',
        'G', 'P', 'B', 'V', 'K', 'X', 'Q', 'J', 'Z'};
    
    int inputSize;

    std::map<char,int> cipherText;
    
    void highestFreq() {
        return std::max_element(cipherText.begin(), cipherText.end(),
        [] (auto a, auto b) { return a->second < b->second; });
    }

    void shiftBy(char& a, int key) {
        a = (!isalpha(a)) ? a : char((a - key) % 26 + 65);
    }

    void parseCipher() 
    {
        std::ifstream cipher;
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
    LetterFreq() {
        parseCipher();
    }

    char* decryptCipher() {
        if (highestFreq() == cipherText)
            return FAILURE;
        int shiftKey = *highestFreq() - 'E';
        // Erase element
        cipherText.erase(highestFreq());
        ifstream cipher;
        cipher.open("cipher-text.txt");
        char letter;
        char decryptText[100000];
        while (cipher.get(letter))
        {
            shiftBy(letter, shiftKey);
            decryptText[i] = letter;
        }
        cipher.close();
        return decryptText;
    }
};

