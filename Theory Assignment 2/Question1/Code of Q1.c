#include <stdio.h>

int main() {
    int i,smallest,smallest2nd;
    int arr[5];
    
    for(i=0;i<5;i++) {
        printf("Enter element - %d: ",i+1);    
        scanf("%d",&arr[i]);
    }
    if(arr[0]<arr[1]) {
        smallest = arr[0];
        smallest2nd = arr[1];
    }
    else {
        smallest = arr[1];
        smallest2nd = arr[0];
    }
    
    for(i=2;i<5;i++) {
        if(arr[i]<smallest) {
			smallest2nd=smallest;
			smallest=arr[i];
        }
        else if(arr[i]<smallest2nd && arr[i]>smallest) {
            smallest2nd=arr[i];
        }
    }
    printf("The second smallest element in the array is: %d",smallest2nd);
 
    return 0;
}