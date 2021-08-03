#pragma once

#include "Types.h"

BOOLEAN stringEquals(const char* stringA, const char* stringB);
BOOLEAN startsWith(const char *substring, const char *string);
int countCharacters(const char *string, size_t stringLength, BOOLEAN ignoreNewLines);
char toUpperCaseCharacter(char character);
char* toUpperCaseString(const char* text);
BOOLEAN isAlphabet(char character);
size_t getStringLength(const char* text);
char* removeNonAlphabeticCharacters(const char* string);
