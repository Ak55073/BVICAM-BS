#include <iostream>

using namespace std;
const int LENGTH = 15;

void merge_sort(int arr[], int start, int mid, int last){
    int temp[LENGTH],k;
    int i=start,j=mid+1,index=start;

    while(i<=mid && j<=last){
        if(arr[i]<arr[j])  {
            temp[index] = arr[i];
            i = i+1;
        } else {
            temp[index] = arr[j];
            j = j+1;
        }
        index++;
    }

    if(i>mid){
        while(j<=last){
            temp[index] = arr[j];
            index++;
            j++;
        }
    } else {
        while(i<=mid){
            temp[index] = arr[i];
            index++;
            i++;
        }
    }

    k = start;
    while(k<index){
        arr[k]=temp[k];
        k++;
    }
}

void divide_arr(int arr[], int start, int last){
    int mid = (start+last) / 2;
    if(start>=last){
        return;
    }
    divide_arr(arr, start, mid);
    divide_arr(arr, mid+1, last);
    merge_sort(arr, start, mid, last);
    printf("\nPass: ");
    for (int i=0;i<LENGTH;i++){
        printf("%d ",arr[i]);
    }
}

int main() {
    printf("Merge sort - Abhinav Kumar\n");
    int arr[] = {85,0,9,3,5,64,12,43,98,1,64,96,37,26,11};
    printf("\nOriginal List: ");
    for (int i=0;i<LENGTH;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    divide_arr(arr,0,LENGTH-1);

    printf("\n\nSorted List: ");
    for (int i=0;i<LENGTH;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
