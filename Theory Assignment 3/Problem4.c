#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int *ratings;
    int totalScore;
};

void inputEmployees(int **ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Enter ratings for employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            do {
                printf("Period %d: ", j + 1);
                scanf("%d", &ratings[i][j]);
            } while (ratings[i][j] < 1 || ratings[i][j] > 10);
        }
    }
}

void displayPerformance(int **ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("\nPerformance of employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("Period %d: %d\n", j + 1, ratings[i][j]);
        }
    }
}

int findEmployeeOfTheYear(int **ratings, int numEmployees, int numPeriods) {
    int highestAvg = -1, topIndex = -1;
    for (int i = 0; i < numEmployees; i++) {
        int sum = 0;
        for (int j = 0; j < numPeriods; j++) {
            sum += ratings[i][j];
        }
        if (sum / numPeriods > highestAvg) {
            highestAvg = sum / numPeriods;
            topIndex = i;
        }
    }
    return topIndex;
}

int findHighestRatedPeriod(int **ratings, int numEmployees, int numPeriods) {
    int highestAvg = -1, bestIndex = -1;
    for (int i = 0; i < numPeriods; i++) {
        int sum = 0;
        for (int j = 0; j < numEmployees; j++) {
            sum += ratings[j][i];
        }
        if (sum / numEmployees > highestAvg) {
            highestAvg = sum / numEmployees;
            bestIndex = i;
        }
    }
    return bestIndex;
}

int findWorstPerformingEmployee(int **ratings, int numEmployees, int numPeriods) {
    int lowestAvg = 9999, lowIndex = -1;
    for (int i = 0; i < numEmployees; i++) {
        int sum = 0;
        for (int j = 0; j < numPeriods; j++) {
            sum += ratings[i][j];
        }
        if (sum / numPeriods < lowestAvg) {
            lowestAvg = sum / numPeriods;
            lowIndex = i;
        }
    }
    return lowIndex;
}


int main() {
    struct Employee *employees;
    int numEmployees, numPeriods;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    printf("Enter the total number of evaluation periods: ");
    scanf("%d", &numPeriods);

    employees = (struct Employee *)malloc(sizeof(struct Employee) * numEmployees);

    for (int i = 0; i < numEmployees; i++) {
        employees[i].ratings = (int *)malloc(sizeof(int) * numPeriods);
    }

    int **ratings = (int **)malloc(sizeof(int *) * numEmployees);
    for (int i = 0; i < numEmployees; i++) {
        ratings[i] = employees[i].ratings;
    }

    inputEmployees(ratings, numEmployees, numPeriods);
    displayPerformance(ratings, numEmployees, numPeriods);

    printf("\n\n==========================================\n");
    printf("Employee %d is the Employee of the Year\n", findEmployeeOfTheYear(ratings, numEmployees, numPeriods) + 1);
    printf("Period %d is the highest-rated period\n", findHighestRatedPeriod(ratings, numEmployees, numPeriods) + 1);
    printf("The worst-performing employee is %d\n", findWorstPerformingEmployee(ratings, numEmployees, numPeriods) + 1);

    for (int i = 0; i < numEmployees; i++) {
        free(employees[i].ratings);
    }
    free(ratings);
    free(employees);

    return 0;
}

