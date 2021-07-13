#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int LIMIT = 30;

void insertionSort(){
    int arr[] = {
        85,7,9,3,5,64,12,43,7,1,
        54,76,23,87,34,76,23,67,23,67,
        67,23,68,24,58,42,76,43,75,24
    };

    int j,key;
    for (int i = 1; i <= LIMIT; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    for (int i=0;i<=LIMIT;i++){
        printf("%d ",arr[i]);
    }
}

void selectionSort(){
    int arr[] = {
        85,7,9,3,5,64,12,43,7,1,
        54,76,23,87,34,76,23,67,23,67,
        67,23,68,24,58,42,76,43,75,24
    };

    for (int i=0;i<=LIMIT;i++){
        for (int j=i+1;j<=LIMIT;j++){
            if (arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i=0;i<=LIMIT;i++){
        printf("%d ",arr[i]);
    }
}

void bubbleSort(){
    int arr[] = {
        85,7,9,3,5,64,12,43,7,1,
        54,76,23,87,34,76,23,67,23,67,
        67,23,68,24,58,42,76,43,75,24
    };

    for (int i=1;i<LIMIT;i++){
        for (int j=0;j<=LIMIT-i;j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for (int i=0;i<=LIMIT;i++){
        printf("%d ",arr[i]);
    }
}

int main(){


    clock_t start, end;
    double time_taken;
    start = clock();
    selectionSort();
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    printf("\nTime taken by Selection Sort: %f sec\n",time_taken);

    start = clock();
    bubbleSort();
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    printf("\nTime taken by Bubble Sort: %f sec\n",time_taken);

    start = clock();
    insertionSort();
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    printf("\nTime taken by Insertion Sort: %f sec\n",time_taken);

//    selectionSort(arr);
//    printf("\n");
//    bubbleSort(arr);
//    printf("\n");
//    insertionSort(arr);


}
