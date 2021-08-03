#include <stdlib.h>

#include "CoincidenceCounter.h"
#include "StringUtilities.h"

const int FREQUENCY_COUNT = 26;

int getCharacterIndex(char character)
{
    return (int)(character - 'A');
}

int* calculateFrequencies(const char *text) {
    int *frequencies = malloc(FREQUENCY_COUNT * sizeof(int));

    for (int i = 0; i < FREQUENCY_COUNT; i++) {
        frequencies[i] = 0;
    }

    size_t textLength = getStringLength(text);

    for (int i = 0; i < textLength; i++) {
        char character = text[i];
        int characterIndex = getCharacterIndex(character);

        frequencies[characterIndex]++;
    }

    return frequencies;
}

char* sanitizeText(const char* text)
{
    char* alphabeticText = removeNonAlphabeticCharacters(text);
    char* upperCaseText = toUpperCaseString(alphabeticText);

    free(alphabeticText);

    return upperCaseText;
}

int performCalculationsOnFrequencies(int *frequencies) {
    int result = 0;

    for (int i = 0; i < FREQUENCY_COUNT; i++) {
        result += frequencies[i] * (frequencies[i] - 1);
    }

    return result;
}

int performCalculationsOnMutualFrequencies(int *frequenciesA, int *frequenciesB) {
    int result = 0;

    for (int i = 0; i < FREQUENCY_COUNT; i++) {
        result += frequenciesA[i] * frequenciesB[i];
    }

    return result;
}

// actual function that calculates Index of Coincidence (IC)...
double calculateIndexOfCoincidence(const char *text) {
    // removes non-alphabetic characters and
    // converts alphabets to upper-case...
    char* sanitizedText = sanitizeText(text);
    int numberOfAlphabets = getStringLength(sanitizedText);
    int *frequencies = calculateFrequencies(sanitizedText);
    int calculationResult = performCalculationsOnFrequencies(frequencies);
    double indexOfCoincidence = calculationResult / (numberOfAlphabets * ((double)numberOfAlphabets - 1));
    
    // releasing memory...
    free(frequencies);
    free(sanitizedText);

    return indexOfCoincidence;
}

// actual function that calculates Mutual Index of Coincidence (MIC)...
double calculateMutualIndexOfCoincidence(const char *textA, const char *textB) {
    // removes non-alphabetic characters and converts alphabets to upper-case...
    char* sanitizedTextA = sanitizeText(textA);
    int numberOfAlphabetsA = getStringLength(sanitizedTextA);
    int *frequenciesA = calculateFrequencies(sanitizedTextA);

    // removes non-alphabetic characters and converts alphabets to upper-case...
    char* sanitizedTextB = sanitizeText(textB);
    int numberOfAlphabetsB = getStringLength(sanitizedTextB);
    int* frequenciesB = calculateFrequencies(sanitizedTextB);

    int calculationResult = performCalculationsOnMutualFrequencies(frequenciesA, frequenciesB);
    double mutualIndexOfCoincidence = calculationResult / ((double)numberOfAlphabetsA * numberOfAlphabetsB);

    // releasing memory...
    free(frequenciesA);
    free(sanitizedTextA);
    free(frequenciesB);
    free(sanitizedTextB);

    return mutualIndexOfCoincidence;
}
