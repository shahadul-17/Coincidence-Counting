#include <stdlib.h>
#include <string.h>

#include "StringUtilities.h"

BOOLEAN startsWith(const char *substring, const char *string)
{
    size_t substringLength = getStringLength(substring);
    size_t stringLength = getStringLength(string);

    if (stringLength < substringLength) { return FALSE; }

    return memcmp(substring, string, substringLength) == 0 ? TRUE : FALSE;
}

BOOLEAN stringEquals(const char *stringA, const char *stringB)
{
    return strcmp(stringA, stringB) == 0 ? TRUE : FALSE;
}

int countCharacters(const char *string, size_t stringLength, BOOLEAN ignoreNewLines)
{
    if (stringLength == -1)
    {
        stringLength = getStringLength(string);
    }

    int count = 0;

    for (int i = 0; i < stringLength; i++)
    {
        if (ignoreNewLines && string[i] == '\n') { continue; }

        count++;
    }

    return count;
}

size_t getStringLength(const char* string)
{
    return strlen(string);
}

char toUpperCaseCharacter(char character)
{
    // if character is not in lower case, we return the character...
    if (character < 'a' || character > 'z')
    {
        return character;
    }

    // converting character to upper case...
    return character - 'a' + 'A';
}

char* toUpperCaseString(const char* string)
{
    size_t stringLength = getStringLength(string);
    char* upperCaseString = malloc((stringLength * sizeof(char)) + 1);

    for (int i = 0; i < stringLength; i++)
    {
        // takes current character...
        const character = string[i];
        // converts the character to upper case...
        const upperCaseCharacter = toUpperCaseCharacter(character);
        // stores the upper case character to the array...
        upperCaseString[i] = upperCaseCharacter;
    }

    upperCaseString[stringLength] = '\0';

    return upperCaseString;
}

BOOLEAN isAlphabet(char character)
{
    return (character >= 'A' && character <= 'Z') ||
        (character >= 'a' && character <= 'z') ? TRUE : FALSE;
}

char* removeNonAlphabeticCharacters(const char* string)
{
    size_t stringLength = getStringLength(string);
    char* alphabeticString = malloc((stringLength * sizeof(char)) + 1);
    int j = 0;

    for (int i = 0; i < stringLength; i++)
    {
        // takes current character...
        const character = string[i];

        // checks if character is A-Z or a-z...
        if ((character >= 'A' && character <= 'Z') ||
            (character >= 'a' && character <= 'z'))
        {
            alphabeticString[j] = character;
            j++;
        }
    }

    alphabeticString[j] = '\0';

    return alphabeticString;
}
