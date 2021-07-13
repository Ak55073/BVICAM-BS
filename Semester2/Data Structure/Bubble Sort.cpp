#include <iostream>

using namespace std;
const int LENGTH = 5;

int main() {
    printf("Bubble sort - Abhinav Kumar\n");

    int arr[] = {14, 33, 27, 35, 10};
    printf("\nOriginal List: ");
    for (int i=0;i<LENGTH;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    for (int i=1;i<LENGTH;i++){
        bool sorted = true;
        for (int j=0;j<LENGTH-i;j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                sorted = false;
            }
        }
        if (sorted){
            break;
        }
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
