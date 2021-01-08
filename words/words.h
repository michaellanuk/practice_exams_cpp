#ifndef WORDS_H
#define WORDS_H

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

void reverse(std::string word, char* reversed);
int compare(std::string one, std::string two);
int recursive_compare(const char* one, const char* two);
int palindrome(std::string word);
int anagram(std::string str1, std::string str2);

#endif