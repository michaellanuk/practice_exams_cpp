#include "soundex.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>

void encode(std::string surname, char* soundex) {
    soundex[0] = surname[0];
    for (int i = 1; i < 4; i++) {
        soundex[i] = '0';
    }
    soundex[4] = '\0';

    char one[4] = {'b', 'f', 'p', 'v'};
    char two[8] = {'c', 'g', 'j', 'k', 'q', 's', 'x', 'z'};
    
    int soundex_position = 1;

    for (int i = 1; i < surname.length(); i++) {
        char digit = '0';
        char prev_digit = soundex[0];

        if (std::find(std::begin(one), std::end(one), surname[i]) 
            != std::end(one)) {
            digit = '1';
        } else if (std::find(std::begin(two), std::end(two), surname[i]) 
            != std::end(two)) {
            digit = '2';
        } else if (surname[i] == 'd' || surname[i] == 't') {
            digit = '3';
        } else if (surname[i] == 'l') {
            digit = '4';
        } else if (surname[i] == 'm' || surname[i] == 'n') {
            digit = '5';
        } else if (surname[i] == 'r') {
            digit = '6';
        } else {
            continue;
        }

        char temp = digit;
        char temp2 = soundex[soundex_position - 1];
        if (temp == temp2) {
            continue;
        }

        soundex[soundex_position] = digit;
        prev_digit = soundex[soundex_position - 1];
        soundex_position++;
        if (soundex_position == 4) {
            break;
        }
    }
}

bool compare(const char* one, const char* two) {
    while (*one != '\0' || *two != '\0') {
        if (*one != *two) {
            return false;
        }
        one++;
        two++;
    }
    return true;
}

/*  counts the number of words in a given sentence
    that share the same Soundex code as a given surname */
int count(std::string surname, std::string sentence) {
    int count = 0;

    char surname_soundex[5];
    encode(surname, surname_soundex);
    
    char soundex[5];

    std::vector<std::string> words;
    std::string word = "";

    for (auto letter : sentence) {
        if (letter == ' ') {
            if (word[0] == surname[0]) {
                words.push_back(word);
            }
            word = "";
        }
        else {
            if (isalpha(letter)) {
                word += letter;
            }
        }
    }
    words.push_back(word);

    for (int i = 0; i < words.size(); i++) {
        encode(words[i], soundex);
        if (compare(soundex, surname_soundex)) {
            count++;
        }
    }
    return count;
}