#include <iostream>

using namespace std;
const int LENGTH = 15;

int divide_arr(int arr[], int low, int high){
    int pivot = arr[high], temp; // pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
        if (arr[j] < pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = divide_arr(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    printf("Quick sort - Abhinav Kumar\n");

    int arr[] = {85,0,9,3,5,64,12,43,98,1,64,96,37,26,11};
    printf("\nOriginal List: ");
    for (int i=0;i<LENGTH;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, LENGTH - 1);

    printf("\nSorted List: ");
    for (int i=0;i<LENGTH;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
