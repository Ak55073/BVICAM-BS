#include <stdio.h>
using namespace std;

const int SIZE = 10;
int LENGTH = 0;

void insertItem(int heap[], int newNum) {
  if (LENGTH == 0) {
    heap[0] = newNum;
    LENGTH++;
  } else {
    heap[LENGTH] = newNum;
    LENGTH++;
    int cur = LENGTH - 1;
    while( cur > 0 && heap[((cur-1)/2)] > heap[cur]){
        int temp = heap[((cur-1)/2)];
        heap[((cur-1)/2)] = heap[cur];
        heap[cur] = temp;
        cur = (cur - 1) / 2;
    }
  }
}

void heapify(int heap[], int LENGTH, int i) {
    if (LENGTH == 1) {
        return;
    } else {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < LENGTH && heap[l] < heap[smallest])
            smallest = l;
        if (r < LENGTH && heap[r] < heap[smallest])
            smallest = r;
        if (smallest != i) {
            int temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;
            heapify(heap, LENGTH, smallest);
        }
    }
}

int deleteItem(int heap[]){
    if (LENGTH==0){
        return -1;
    }
    int deleted = heap[0];
    heap[0] = heap[LENGTH-1];
    LENGTH--;
    heapify(heap, LENGTH, 0);
    return deleted;
}

int main() {
    int heap[SIZE], arr[SIZE]={8,4,7,1,16,19,3,6,9,5};
    printf("Sorting Array using Min-Heap - Abhinav Kumar\n\n");
    printf("Original Array: ");
    for(int i=0;i<SIZE; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    // Inserting array element to min heap
    for(int i=0;i<SIZE; i++){
        insertItem(heap, arr[i]);
    }

    // Poping element from min heap and inserting into array
    for(int i=0;i<SIZE; i++){
        arr[i] = deleteItem(heap);
    }

    printf("Sorted  Array : ");
    for(int i=0;i<SIZE; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
