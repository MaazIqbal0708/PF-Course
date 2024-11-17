#include <stdio.h>

int main(){
    int n, arr[n],max=0;
    printf("Enter size of array : ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Enter number %d : ", i+1);
        scanf("%d", &arr[i]);
        if(arr[i]>max) max=arr[i];
    }

    printf("\nHorizontal Histogram:\n");
    for(int i=0; i<n; i++){
        printf("Value %d: ", i+1);
        for(int j=0; j<arr[i]; j++){
            printf("* ");
        }
        printf("\n");
    }

    printf("Vertical Histogram:\n");
    for(int i=0; i<max; i++){
        for(int j=0; j<n; j++){
            if(arr[j]>=max-i) printf("* ");
            else printf("  ");
        }
        printf("\n");
        if(i==max-1){
            for(int i=0; i<n; i++){
                printf("%d ",arr[i]);
            }
        }
    }
}