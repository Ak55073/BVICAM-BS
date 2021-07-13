#include <iostream>
#include <conio.h>

using namespace std;
int LENGTH = 0;

void heapify(int heap[], int LENGTH, int i) {
    if (LENGTH == 1) {
        printf("Single element in the heap");
    } else {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < LENGTH && heap[l] > heap[largest])
            largest = l;
        if (r < LENGTH && heap[r] > heap[largest])
            largest = r;
        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            heapify(heap, LENGTH, largest);
        }
    }
}

void insertItem(int heap[], int newNum) {
    if (LENGTH == 0) {
        heap[0] = newNum;
        LENGTH += 1;
    } else {
        heap[LENGTH] = newNum;
        LENGTH += 1;
        for (int i = LENGTH / 2 - 1; i >= 0; i--) {
            heapify(heap, LENGTH, i);
        }
    }
}
void deleteRoot(int heap[], int num) {
    int i, temp;
    for (i = 0; i < LENGTH; i++) {
        if (num == heap[i])
            break;
    }
    temp = heap[i];
    heap[i] = heap[LENGTH - 1];
    heap[LENGTH - 1] = temp;
    LENGTH -= 1;
    for (int i = LENGTH / 2 - 1; i >= 0; i--) {
        heapify(heap, LENGTH, i);
    }
}

void printheap(int heap[], int LENGTH) {
    for (int i = 0; i < LENGTH; ++i)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int heap[10], opt, temp;
    bool exe = true;
    printf("Max Heap - Abhinav Kumar");
    printf("\n\n1.Add Item\n2.Delete Item\n3.Display\n0.Exit\n");
    while (exe){
        printf("\nHeap: ");
        printheap(heap, LENGTH);
        printf("Enter: ");
        scanf("%d",&opt);
        switch (opt){
            case 0:
                exe = false;
                break;
            case 1:
                printf("Enter an item to insert: ");
                scanf("%d",&temp);
                insertItem(heap, temp);
                break;
            case 2:
                printf("Enter an item to delete: ");
                scanf("%d",&temp);
                deleteRoot(heap, temp);
                break;
            case 3:
                printheap(heap, LENGTH);
                break;
        }
    }

    return 0;
}
