#include <stdio.h>
#include <string.h>

void compressWord(char *word, char *compressedWord, int *removedCount) {
    int index = 0, removed = 0;
    char prevChar = '\0';

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] != prevChar) {
            compressedWord[index++] = word[i];
            prevChar = word[i];
        } else {
            removed++;
        }
    }
    compressedWord[index] = '\0';
    *removedCount = removed;
}

void compressWords(char words[][100], int numWords) {
    int totalRemoved = 0;

    printf("Compressed words:\n");
    for (int i = 0; i < numWords; i++) {
        char compressedWord[100];
        int removedCount = 0;

        compressWord(words[i], compressedWord, &removedCount);
        totalRemoved += removedCount;

        printf("%s -> %s (Characters removed: %d)\n", words[i], compressedWord, removedCount);
    }

    printf("\nTotal characters removed across all words: %d\n", totalRemoved);
}

int main() {
    int numWords;

    printf("Enter the number of words: ");
    scanf("%d", &numWords);
    
    getchar();

    char words[numWords][100];
    for (int i = 0; i < numWords; i++) {
        printf("Enter word %d: ", i + 1);
        fgets(words[i], 100, stdin);

        words[i][strcspn(words[i], "\n")] = '\0';
    }

    compressWords(words, numWords);

    return 0;
}
