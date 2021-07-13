#include <iostream>

using namespace std;
const int LENGTH = 15;

int main() {
    printf("Selection sort - Abhinav Kumar\n\n");

    int arr[] = {85,0,9,3,5,64,12,43,98,1,64,96,37,26,11};
    printf("\nOriginal List: ");
    for (int i=0;i<LENGTH;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    for (int i=0;i<LENGTH;i++){

        int least = i;
        for (int j=i+1;j<LENGTH;j++){
            if (arr[least]>arr[j]){
                least = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[least];
        arr[least] = temp;

        printf("\nPass %2d: ",i);
        for (int i=0;i<LENGTH;i++){
            printf("%d ",arr[i]);
        }
    }

    printf("\n\nSorted List: ");
    for (int i=0;i<LENGTH;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}
