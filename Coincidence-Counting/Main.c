#include <stdio.h>

#include "StringUtilities.h"
#include "CoincidenceCounter.h"

int main(int argc, char* argv[], char* envp[])
{
    if (argc > 2 && stringEquals(argv[1], "ic"))
    {
        double indexOfCoincidence = calculateIndexOfCoincidence(argv[2]);

        printf_s("Index of Coincidence (IC): %lf\n", indexOfCoincidence);
    }
    else if (argc > 3 && stringEquals(argv[1], "mic"))
    {
        double mutualIndexOfCoincidence = calculateMutualIndexOfCoincidence(argv[2], argv[3]);

        printf_s("Mutual Index of Coincidence (MIC): %lf\n", mutualIndexOfCoincidence);
    }
    else
    {
        printf_s("Invalid command line argument(s) provided.");

        return -1;
    }

	return 0;
}
