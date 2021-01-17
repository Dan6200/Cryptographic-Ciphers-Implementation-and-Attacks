#include <fstream>
#include <map>
#include <cctype>
#include <algorithm>

class LetterFreq {
    char FAILURE[10] = "TERMINATE";
    char decryptText[100000];
    
    int inputSize;

    std::map<char,int> cipherText;
    
    std::map<char,int>::iterator highestFreq() {
        return std::max_element(cipherText.begin(), cipherText.end(),
        [] (auto a, auto b) { return a.second < b.second; });
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

    const char* decryptCipher() {
        while(!isalpha(highestFreq()->first)) {
            // Erase element
            cipherText.erase(highestFreq());
        }

        if (highestFreq() == cipherText.end())
            return static_cast<const char*>(FAILURE);
        int shiftKey = highestFreq()->first - 'E';
        // Erase element
        cipherText.erase(highestFreq());
        std::ifstream cipher;
        cipher.open("cipher-text.txt");
        char letter;
        int i = 0;
        while (cipher.get(letter))
        {
            shiftBy(letter, shiftKey);
            decryptText[i++] = letter;
        }
        cipher.close();
        return static_cast<const char*>(decryptText);
    }
};

