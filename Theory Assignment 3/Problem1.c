#include<stdio.h>
#include<string.h>

typedef struct {
    int year;
    int month;
    int day; 
} Date;

typedef struct {
    int employeeCode; 
    char employeeName[100];
    Date dateOfJoining;
} Employee;

void inputEmployee(Employee *emp){
    printf("Enter Employee Code: ");
    scanf("%d", &emp->employeeCode);
    getchar();

    printf("Enter Employee Name: ");
    fgets(emp->employeeName, sizeof(emp->employeeName), stdin);
    emp->employeeName[strcspn(emp->employeeName , "\n")] = '\0';
    
    printf("Enter Date of Joining (dd/mm/yyyy): ");
    scanf("%d %d %d", &(emp->dateOfJoining.day), &(emp->dateOfJoining.month), &(emp->dateOfJoining.year));
    getchar();
}

void printEmployee(Employee *emp){
    printf("Employee Code: %d\n", emp->employeeCode);
    printf("Employee Name: %s\n", emp->employeeName);
    printf("Date of Joining: (dd/mm/yyyy) %d/%d/%d \n", emp->dateOfJoining.day, emp->dateOfJoining.month , emp->dateOfJoining.year);
}

int calculateTenure(Employee *emp, Date *currentDate) {
    int tenureYears = currentDate->year - emp->dateOfJoining.year;
    int tenureMonths = currentDate->month - emp->dateOfJoining.month;
    int tenureDays = currentDate->day - emp->dateOfJoining.day;

    if (tenureDays < 0) {
        tenureMonths--;
        tenureDays += 30; 
    }
    if (tenureMonths < 0) {
        tenureYears--;
        tenureMonths += 12;
    }
    printf("Tenure of Employee %s: %d Years, %d Months, %d Days\n", emp->employeeName, tenureYears, tenureMonths, tenureDays);
    return tenureYears; 
}

int main(){
    Employee employees[4];
    int i, eligibleCount = 0, tenure = 0;
    Date currentDate;

    for(i = 0; i < 4; i++){
        inputEmployee(&employees[i]);
    }

    printf("Enter the current date (dd/mm/yyyy): ");
    scanf("%d %d %d", &(currentDate.day), &(currentDate.month), &(currentDate.year));
    getchar();

    for(i = 0; i < 4; i++){
        printEmployee(&employees[i]);
        tenure = calculateTenure(&employees[i], &currentDate);
        if(tenure >= 3){
            eligibleCount++;
        }
    }
    printf("The total number of employees with tenure of 3 years or more is %d\n", eligibleCount);

    return 0;
}
