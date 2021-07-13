#include <iostream>
#include <math.h>

using namespace std;
const int LENGTH = 15;

int countDigit(int* arr){
    int high=0,digit=0;
    for(int i=0;i<LENGTH;i++){
        if (arr[i] > high){
            high = arr[i];
        }
    }

    while (high>0){
        digit++;
        high /= 10;
    }
    return digit;
}

int main() {
    printf("Radix sort - Abhinav Kumar\n");

    int limit,wildcard,e1;

    int arr[] = {845,680,9,3,3425,64,142,43,98,221,64,96,337,26,131};
    printf("\nOriginal List: ");
    for (int i=0;i<LENGTH;i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n");

    limit = countDigit(arr);

    for(int i=0;i<limit;i++){
        printf("Sorting %d place",i+1);
        int bucket[10][LENGTH] = {0};
        for(int j=0;j<LENGTH;j++){
            wildcard = pow(10,i);
            if (arr[j] > wildcard){
                e1 = int(arr[j]/ wildcard) % 10;
            } else{
                e1 = 0;
            }
            for(int z=0;z<LENGTH;z++){
                if (bucket[e1][z] == 0) {
                    bucket[e1][z] = arr[j];
                    break;
                }
            }
        }

        for (int b=0;b<10;b++){
            printf("\nBucket %d: ",b);
            for (int c=0;c<LENGTH;c++){
                if (bucket[b][c]==0){
                    break;
                }
                if (c!=0)
                    printf(", ");
                printf("%d",bucket[b][c]);
            }
        }

        int ind=0;
        for (int b=0;b<10;b++){
            for (int c=0;c<LENGTH;c++){
                if (bucket[b][c]!=0){
                    arr[ind] = bucket[b][c];
                    ind++;
                } else{
                    break;
                }
            }
        }

        printf("\nSorted on digit %d: ",i+1);
        for (int out=0;out<LENGTH;out++){
            printf("%d ",arr[out]);
        }
        printf("\n\n");
    }

    printf("Sorted List: ");
    for (int i=0;i<LENGTH;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
