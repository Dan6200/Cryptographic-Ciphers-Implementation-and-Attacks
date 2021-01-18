#include <fstream>
#include <map>
#include <cctype>
#include <algorithm>

class Caesar_Analsis {
    const char FAILURE[10] = "TERMINATE";

    char decryptText[100000];

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

    const int KeySpace = 26;
    const int Offset = 65;

public:
    Caesar_Analsis() {
        parseCipher();
    }

    const char* handleFailure() { return static_cast<const char*>(FAILURE); }

    std::map<char,int> cipherText;

    int getKey(int y, int x) {
        /* k === y - x mod p */
        int key = y - x; 
        if (key < 0)
            key += KeySpace;
        return key;
    }

    const char* decryptCipher(char commnLettr) {
        while(highestFreq() != cipherText.end() && !isalpha(highestFreq()->first)) {
            // Erase element
            cipherText.erase(highestFreq());
        }

        if (highestFreq() == cipherText.end())
            return handleFailure();
        int shiftKey = getKey(highestFreq()->first, commnLettr);
        // Erase element
        cipherText.erase(highestFreq());
        std::ifstream cipher;
        cipher.open("cipher-text.txt");
        char letter;
        int i = 0;
        while (cipher.get(letter))
        {
            shiftBy(letter, shiftKey);
            setDecryptText(letter, i);
            i++;
        }
        cipher.close();
        return getDecryptText();
    }

    std::map<char,int>::iterator highestFreq() {
        return std::max_element(cipherText.begin(), cipherText.end(),
        [] (auto a, auto b) { return a.second < b.second; });
    }

    void setDecryptText(char letter, int index) { decryptText[index] = letter; }

    const char* getDecryptText() { 
        return static_cast<const char*>(decryptText); 
    }

    void shiftBy(char& a, int key) {
        /*
            k = key,
            p = KeySpace,
            C = Offset,
            x = plain text,
            y = cipher text

            x = [(y - C) - k mod p] + C
        */
        if (isalpha(a))
        {
            int y = a;
            int x;
            int diff = (y - Offset) - key; 
            // mod p:
            if (diff < 0) diff += KeySpace;
            x = diff + Offset;
            a = char(x);
        }
    }

};

