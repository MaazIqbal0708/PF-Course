#include <stdio.h>

void upDown(char grid[][5], int*, int*, int*, int*);
void leftRight(char grid[][5], int*, int*, int*, int*);
void printGrid(char grid[5][5]);

int main(){
    char grid[5][5] = {
    {' ', ' ', 'I', 'X', ' '},
    {' ', 'X', ' ', ' ', ' '},
    {'I', ' ', 'X', 'X', ' '},
    {' ', ' ', ' ', 'I', 'X'},
    {' ', 'X', ' ', ' ', 'P'}
    };

    printf("Welcome to Grid Adventure Game.\n\n");
    printf("Enter following keys to play\nW: up\nS: down\nA: Left\nD: Right\nQ: Quit.\n\n");
    printf("Let's Start\n");
    int p1=4, p2=4, item=0;

    char a;
    while(a!='Q'){
        int p3=0;
        printGrid(grid);
        printf("\nEnter your move: ");
        scanf(" %c", &a);

        if(a=='W'){
            p3=p1-1;
            upDown(grid, &p2, &p1, &p3, &item);
        }
        else if(a=='S'){
            p3=p1+1;
            upDown(grid, &p2, &p1, &p3, &item);
        }
        else if(a=='A'){
            p3=p2-1;
            leftRight(grid, &p1, &p2, &p3, &item);
        }
        else if(a=='D'){
            p3=p2+1;
            leftRight(grid, &p1, &p2, &p3, &item);
        }
        else if(a=='Q'){ 
            printf("\nThe game has ended\n");
            printf("Collected items are %d", item);
            return 0;
        }
        else printf("Invalid Input\n");
    }
}

void printGrid(char grid[5][5]){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("|'%c'", grid[i][j]);
        }
        printf("|\n");
    }
}

void upDown(char grid[][5], int *i, int *j, int *k, int *item){
    if(*k>=0 && *k<=4){
        if(grid[*k][*i]==' ' || grid[*k][*i]=='I'){
            if(grid[*k][*i]=='I') (*item)++;
            grid[*j][*i]=' ';
            grid[*k][*i]='P';
            *j=*k;
        }
    }
    else printf("Invalid Input\n");
    return;
}

void leftRight(char grid[][5], int *i, int *j, int *k, int *item){
    if(*k>=0 && *k<=4){
        if(grid[*i][*k]==' ' || grid[*i][*k]=='I'){
            if(grid[*i][*k]=='I') (*item)++;
            grid[*i][*j]=' ';
            grid[*i][*k]='P';
            *j=*k;
        }
    }
    else printf("Invalid Input\n");
    return;
}