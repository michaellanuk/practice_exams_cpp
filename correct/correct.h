#ifndef CORRECT_H
#define CORRECT_H

#include <iostream>
#include <string>
#include <vector>

void ascii_to_binary(char letter, char *output);
char binary_to_ascii(const char *binary);
void text_to_binary(std::string text, char* binary);
void binary_to_text(std::string digits, char* text);
void add_error_correction(std::string digits, char* correct);
void error_correct_bits(std::string bits, char* correct, int offset);
int decode(std::string bits, char* decoded);
void decode(std::string bits, char* decoded, int offset, int &errors);

#endif
