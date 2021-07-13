#include <iostream>

using namespace std;

const int LENGTH = 15;

int main() {
    printf("Shell sort - Abhinav Kumar\n");

    int arr[] = {85,0,9,3,5,64,12,43,98,1,64,96,37,26,11};
    printf("\nOriginal List: ");
    for (int i=0;i<LENGTH;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int pass =0;
    for (int gap=LENGTH/2;gap>0;gap=gap/2){
        for (int i=0;i<LENGTH;i++){
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
        printf("\nPass %2d: ",++pass);
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
