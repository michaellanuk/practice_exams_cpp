#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

void encode(std::string surname, char* soundex);
bool compare(const char* one, const char* two);
int count(std::string surname, std::string sentence);

#endif