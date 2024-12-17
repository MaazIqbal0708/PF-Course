#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email) {
    int atCount = 0;
    int dotFound = 0;
    int i = 0;

    if (email == NULL || strlen(email) == 0) {
        return 0;
    }

    while (email[i] != '\0') {
        if (email[i] == '@') {
            atCount++;
        } else if (email[i] == '.') {
            dotFound = 1;
        }
        i++;
    }

    if (atCount == 1 && dotFound) {
        return 1;
    }
    return 0;
}

int main() {
    char *email = NULL;
    size_t length = 0;

    printf("Enter an email address: ");
    getline(&email, &length, stdin);
    
    email[strcspn(email, "\n")] = '\0';
	
    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

    free(email);
    return 0;
}

