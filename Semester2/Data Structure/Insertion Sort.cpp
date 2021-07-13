#include <iostream>

using namespace std;
const int LENGTH = 15;

int main() {
    printf("Insertion sort - Abhinav Kumar\n\n");

    int arr[] = {85,0,9,3,5,64,12,43,98,1,64,96,37,26,11};
    printf("\nOriginal List: ");
    for (int i=0;i<LENGTH;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    int j,key;
    for (int i = 1; i < LENGTH; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

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
