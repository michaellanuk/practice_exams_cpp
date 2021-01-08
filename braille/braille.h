#ifndef BRAILLE_H
#define BRAILLE_H

#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>

int encode_character(char ch, char* braille);
void encode(const char* word, char* braille);
void print_braille(const char* word, std::ostream& cout);

#endif