#ifndef PIGLATIN_H
#define PIGLATIN_H

#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <vector>

int findFirstVowel(std::string word);
void translateWord(std::string word, char* translated);
void translateStream(std::istream &cin, std::ostream &cout);
void recursive_translate(std::string word, char* translated, int pos);

#endif