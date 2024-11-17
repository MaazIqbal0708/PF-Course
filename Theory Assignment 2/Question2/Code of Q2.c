#include <stdio.h>
#include <string.h>

void calculateFrequency(char *slogan) {
    int frequency[256] = {0};

    for (int i = 0; slogan[i] != '\0'; i++) {
        frequency[(int)slogan[i]]++;
    }

    printf("Character frequencies for \"%s\":\n", slogan);
    printf("{");
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            printf("'%c': %d, ", i, frequency[i]);
        }
    }
    printf("\b\b}\n");
}

int main() {
    int numSlogans;

    printf("Enter the number of slogans: ");
    scanf("%d", &numSlogans);

    getchar();

    char slogans[numSlogans][100];

    for (int i = 0; i < numSlogans; i++) {
        printf("Enter slogan %d: ", i + 1);
        fgets(slogans[i], 100, stdin);

        slogans[i][strcspn(slogans[i], "\n")] = '\0';
    }

    for (int i = 0; i < numSlogans; i++) {
        calculateFrequency(slogans[i]);
        printf("\n");
    }

    return 0;
}
