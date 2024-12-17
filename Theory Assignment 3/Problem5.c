#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Animal {
    char speciesName[100];]
    char **supplies;
};

void addSpecies(struct Animal **inventory, int *numSpecies, int numSupplies) {
    (*numSpecies)++;
    *inventory = (struct Animal *)realloc(*inventory, (*numSpecies) * sizeof(struct Animal));
    (*inventory)[*numSpecies - 1].supplies = (char **)malloc(numSupplies * sizeof(char *));
    for (int i = 0; i < numSupplies; i++) {
        (*inventory)[*numSpecies - 1].supplies[i] = (char *)malloc(100 * sizeof(char));
    }
    printf("Enter species name: ");
    scanf("%s", (*inventory)[*numSpecies - 1].speciesName);
    for (int i = 0; i < numSupplies; i++) {
        printf("Enter supply %d for species %s: ", i + 1, (*inventory)[*numSpecies - 1].speciesName);
        scanf("%s", (*inventory)[*numSpecies - 1].supplies[i]);
    }
}

void updateSpecies(struct Animal *inventory, int numSupplies, int speciesIndex) {
    for (int i = 0; i < numSupplies; i++) {
        printf("Enter new supply %d for species %s: ", i + 1, inventory[speciesIndex].speciesName);
        scanf("%s", inventory[speciesIndex].supplies[i]);
    }
}

void removeSpecies(struct Animal **inventory, int *numSpecies, int speciesIndex, int numSupplies) {
    for (int i = speciesIndex; i < (*numSpecies) - 1; i++) {
        strcpy((*inventory)[i].speciesName, (*inventory)[i + 1].speciesName);
        for (int j = 0; j < numSupplies; j++) {
            strcpy((*inventory)[i].supplies[j], (*inventory)[i + 1].supplies[j]);
        }
    }
    (*numSpecies)--;
    *inventory = (struct Animal *)realloc(*inventory, (*numSpecies) * sizeof(struct Animal));
}

void displayInventory(struct Animal *inventory, int numSpecies, int numSupplies) {
    for (int i = 0; i < numSpecies; i++) {
        printf("\nSpecies: %s\n", inventory[i].speciesName);
        for (int j = 0; j < numSupplies; j++) {
            printf("Supply %d: %s\n", j + 1, inventory[i].supplies[j]);
        }
    }
}


int main() {
    int end = 1;
    int numSpecies, numSupplies;

    printf("Enter the number of species: ");
    scanf("%d", &numSpecies);
    printf("Enter the number of supplies: ");
    scanf("%d", &numSupplies);
=
    struct Animal *inventory = (struct Animal *)malloc(numSpecies * sizeof(struct Animal));

    for (int i = 0; i < numSpecies; i++) {
        inventory[i].supplies = (char **)malloc(numSupplies * sizeof(char *));
        for (int j = 0; j < numSupplies; j++) {
            inventory[i].supplies[j] = (char *)malloc(100 * sizeof(char));
        }
    }

    // Input species and supplies
    for (int i = 0; i < numSpecies; i++) {
        printf("Enter the species name %d: ", i + 1);
        scanf("%s", inventory[i].speciesName);
        for (int j = 0; j < numSupplies; j++) {
            printf("Enter supply %d for species %s: ", j + 1, inventory[i].speciesName);
            scanf("%s", inventory[i].supplies[j]);
        }
    }

    while (end) {
        int option;
        printf("\n1. Add Species\n");
        printf("2. Update Species Supplies\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addSpecies(&inventory, &numSpecies, numSupplies);
                break;

            case 2:
                {
                    int speciesIndex;
                    printf("Enter the index (0-%d) of species to update: ", numSpecies - 1);
                    scanf("%d", &speciesIndex);
                    if (speciesIndex >= 0 && speciesIndex < numSpecies) {
                        updateSpecies(inventory, numSupplies, speciesIndex);
                    } else {
                        printf("Invalid species index.\n");
                    }
                }
                break;

            case 3:
                {
                    int speciesIndex;
                    printf("Enter the index (0-%d) of species to remove: ", numSpecies - 1);
                    scanf("%d", &speciesIndex);
                    if (speciesIndex >= 0 && speciesIndex < numSpecies) {
                        removeSpecies(&inventory, &numSpecies, speciesIndex, numSupplies);
                    } else {
                        printf("Invalid species index.\n");
                    }
                }
                break;

            case 4:
                displayInventory(inventory, numSpecies, numSupplies);
                break;

            case 5:
                end = 0;
                printf("Exiting...\n");
                break;
        }
    }

    for (int i = 0; i < numSpecies; i++) {
        for (int j = 0; j < numSupplies; j++) {
            free(inventory[i].supplies[j]);
        }
        free(inventory[i].supplies);
    }
    free(inventory);

    return 0;
}


