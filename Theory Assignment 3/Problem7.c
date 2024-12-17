#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_CATEGORIES 5
#define MAX_DEVICES 3
#define MAX_CONTENT 10

struct ContentMetadata {
    char title[50];
    float rating;
    int duration;
    char format[20];
};

struct UserProfile {
    char username[30];
    double *engagementMatrixRow;
    double **deviceMatrix;
};

struct ContentCategory {
    struct ContentMetadata *items[MAX_CONTENT];
};

void setupUserProfiles(struct UserProfile userProfiles[], int totalUsers);
void initializeEngagementMatrixRow(struct UserProfile *userProfile);
void initializeDeviceMatrix(struct UserProfile *userProfile);
void updateUserEngagement(struct UserProfile *userProfile, int categoryIndex, double value);
void showUserEngagement(const struct UserProfile *userProfile);
void setupContentCategories(struct ContentCategory contentCategories[]);
void addContentMetadata(struct ContentCategory *contentCategory, int index, const char *title, float rating, int duration, const char *format);
void showContentCategory(const struct ContentCategory *contentCategory);

int main() {
    struct UserProfile userProfiles[MAX_USERS];
    struct ContentCategory contentCategories[MAX_CATEGORIES];
    
    setupUserProfiles(userProfiles, MAX_USERS);
    setupContentCategories(contentCategories);
    
    addContentMetadata(&contentCategories[0], 0, "Action Movie 1", 8.5, 120, "H.264");
    addContentMetadata(&contentCategories[1], 0, "Drama Movie 1", 7.8, 90, "H.265");
    
    updateUserEngagement(&userProfiles[0], 0, 5.0);
    updateUserEngagement(&userProfiles[0], 1, 3.5);
    
    printf("Engagement Metrics for %s:\n", userProfiles[0].username);
    showUserEngagement(&userProfiles[0]);
    
    printf("\nAction Category Content:\n");
    showContentCategory(&contentCategories[0]);
    
    return 0;
}

void setupUserProfiles(struct UserProfile userProfiles[], int totalUsers) {
    for (int i = 0; i < totalUsers; i++) {
        snprintf(userProfiles[i].username, sizeof(userProfiles[i].username), "User%d", i + 1);
        userProfiles[i].engagementMatrixRow = (double *)malloc(MAX_CATEGORIES * sizeof(double));
        memset(userProfiles[i].engagementMatrixRow, 0, MAX_CATEGORIES * sizeof(double));
        initializeDeviceMatrix(&userProfiles[i]);
    }
}

void initializeDeviceMatrix(struct UserProfile *userProfile) {
    userProfile->deviceMatrix = (double **)malloc(MAX_DEVICES * sizeof(double *));
    for (int i = 0; i < MAX_DEVICES; i++) {
        userProfile->deviceMatrix[i] = (double *)malloc(3 * sizeof(double));
        memset(userProfile->deviceMatrix[i], 0, 3 * sizeof(double));
    }
}

void updateUserEngagement(struct UserProfile *userProfile, int categoryIndex, double value) {
    if (categoryIndex >= 0 && categoryIndex < MAX_CATEGORIES) {
        userProfile->engagementMatrixRow[categoryIndex] += value;
    }
}

void showUserEngagement(const struct UserProfile *userProfile) {
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        printf("Category %d Engagement: %.2f\n", i + 1, userProfile->engagementMatrixRow[i]);
    }
}

void setupContentCategories(struct ContentCategory contentCategories[]) {
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        for (int j = 0; j < MAX_CONTENT; j++) {
            contentCategories[i].items[j] = NULL;
        }
    }
}

void addContentMetadata(struct ContentCategory *contentCategory, int index, const char *title, float rating, int duration, const char *format) {
    if (index >= 0 && index < MAX_CONTENT) {
        contentCategory->items[index] = (struct ContentMetadata *)malloc(sizeof(struct ContentMetadata));
        strncpy(contentCategory->items[index]->title, title, sizeof(contentCategory->items[index]->title));
        contentCategory->items[index]->rating = rating;
        contentCategory->items[index]->duration = duration;
        strncpy(contentCategory->items[index]->format, format, sizeof(contentCategory->items[index]->format));
    }
}

void showContentCategory(const struct ContentCategory *contentCategory) {
    for (int i = 0; i < MAX_CONTENT; i++) {
        if (contentCategory->items[i] != NULL) {
            printf("Title: %s\nRating: %.1f\nDuration: %d mins\nFormat: %s\n",
                   contentCategory->items[i]->title,
                   contentCategory->items[i]->rating,
                   contentCategory->items[i]->duration,
                   contentCategory->items[i]->format);
        }
    }
}
