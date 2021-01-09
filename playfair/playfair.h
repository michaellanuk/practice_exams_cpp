#ifndef PLAYFAIR_H
#define PLAYFAIR_H

#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>

void prepare(std::string input, char* prepared);
void grid(std::string codeword, char square[6][6]);
void bigram(char square[6][6], char in1, char in2, char &out1, char &out2);
void encode(char square[6][6], char* word, char* encoded);

#endif