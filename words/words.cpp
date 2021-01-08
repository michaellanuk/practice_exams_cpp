#include "words.h"

void reverse(std::string word, char* reversed) {
    int length = word.length();

    for (int i = 0, j = length - 1; i < length; i++, j--) {
        reversed[i] = word[j];
    }
}

/*  below function removes non-alpha characters
    and converts to upper-case before recursively
    calling compare function */
int compare(std::string one, std::string two) {
    char one_1[one.length()];
    char two_1[two.length()];

    int arr_iter = 0;
    for (int i = 0; i < one.length(); i++) {
        if (isalpha(one[i])) {
            char c = toupper(one[i]);
            one_1[arr_iter] = c;
            arr_iter++;
        }
    }

    arr_iter = 0;
    for (int i = 0; i < two.length(); i++) {
        if (isalpha(two[i])) {
            char c = toupper(two[i]);
            two_1[arr_iter] = c;
            arr_iter++;
        }
    }

    return recursive_compare(one_1, two_1);
}

int recursive_compare(const char* one, const char* two) {
    if (*one != *two) {
        return 0;
    }
    
    while (*one != '\0' && *two != '\0') {
        one++;
        two++;
        return recursive_compare(one, two);
    }

    return true;
}

/*  function removes punctuation and capitalises characters
    before reversing strings and then comparing */
int palindrome(std::string word) {
    std::string word_alpha = "";

    for (int i = 0; i < word.length(); i++) {
        if (isalpha(word[i])) {
            char c = toupper(word[i]);
            word_alpha.push_back(c);
        }
    }

    char reversed[word_alpha.length()];
    reverse(word_alpha, reversed);

    if (compare(word_alpha, reversed)) {
        return 1;
    }
    return 0;
}

/*  function removes punctuation, capitalises characters, sorts
    the new strings and compares them against each other */
int anagram(std::string str1, std::string str2) {
    std::string str1_alpha = "";
    std::string str2_alpha = "";

    for (int i = 0; i < str1.length(); i++) {
        if (isalpha(str1[i])) {
            char c = toupper(str1[i]);
            str1_alpha.push_back(c);
        }
    }
    for (int i = 0; i < str2.length(); i++) {
        if (isalpha(str2[i])) {
            char c = toupper(str2[i]);
            str2_alpha.push_back(c);
        }
    }
    std::sort(str1_alpha.begin(), str1_alpha.end());
    std::sort(str2_alpha.begin(), str2_alpha.end());

    if (compare(str1_alpha, str2_alpha)) {
        return 1;
    }
    return 0;
}