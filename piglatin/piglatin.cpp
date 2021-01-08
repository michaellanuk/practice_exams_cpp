#include "piglatin.h"

int findFirstVowel(std::string word) {
    std::string vowels = "aeiouAEIOU";

    for (int i = 0; i < word.length(); i++) {
        if (std::find(std::begin(vowels), std::end(vowels), word[i]) 
            != std::end(vowels)) {
                return i;
        }
    }

    return -1;
}

void translateWord(std::string word, char* translated) {
    /* clear translated array */
    int i = 0;
    while (translated[i] != '\0') {
        translated[i] = '\0';
        i++;
    }

    if (!isalpha(word[0])) {
        for (int i = 0; i < word.length(); i++) {
            translated[i] = word[i];
        }
        return;
    }

    /* if word begins with a vowel just add 'way' */
    if (findFirstVowel(word) == 0) {
        for (int i = 0; i < word.length(); i++) {
            translated[i] = word[i];
        }
        translated[word.length()] = 'w';
        translated[word.length() + 1] = 'a';
        translated[word.length() + 2] = 'y';
        return;
    }

    /* if there are no vowels just add 'ay' */
    if (findFirstVowel(word) == -1) {
        for (int i = 0; i < word.length(); i++) {
            translated[i] = word[i];
        }
        translated[word.length()] = 'a';
        translated[word.length() + 1] = 'y';
        return;
    }

    std::string movedLetters = "";
    int firstVowel = findFirstVowel(word);
    for (int i = 0; i < firstVowel; i++) {
        movedLetters.push_back(word[i]);
    }

    for (int i = firstVowel, j = 0; i < word.length(); i++, j++) {
        if (isupper(word[0])) {
            translated[0] = toupper(word[firstVowel]);
        }
        translated[j] = word[i];
    }

    int pos = word.length() - movedLetters.length();
    for (int i = 0, j = pos; i < movedLetters.length(); i++, j++) {
        translated[j] = tolower(movedLetters[i]);
    }
    
    translated[word.length()] = 'a';
    translated[word.length() + 1] = 'y';
    return;
}

void translateStream(std::istream &cin, std::ostream &cout) {
    char translated[512];
    char translated_word[100];
    for (int i = 0; i < 100; i++) {
        translated[i] = '\0';
    }

    std::vector<std::string> words;
    char ch = '0';
    int i = 0;
    cin >> std::noskipws;

    std::string word = "";
    while (!cin.eof()) {
        cin >> ch;
        if (ispunct(ch) || isspace(ch)) {
            words.push_back(word);
            word = "";
            word.push_back(ch);
            words.push_back(word);
            word = "";
            continue;
        }
        word.push_back(ch);
        i++;
    }

    int ii = 0;
    for (int i = 0; i < words.size(); i++) {
        translateWord(words[i], translated_word);
        int j = 0;
        while (translated_word[j] != '\0') {
            translated[ii] = translated_word[j];
            j++;
            ii++;
        }
    }

    i = 0;
    while (true) {
        if (translated[i] == '\0') {
            break;
        }
        std::cout << translated[i];
        i++;
    }
    std::cout << '\n';
}