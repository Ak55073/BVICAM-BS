#include <iostream>
#include <conio.h>

using namespace std;
const int LENGTH = 5;
int arr[LENGTH] = {0};
int END_FRONT = -1;
int END_BACK = LENGTH;

void addItem(int temp, bool start){
    if (start){
        if (END_FRONT+1==END_BACK || END_FRONT+1 == LENGTH){
            printf("Front Queue is Full!");
            return;
        }
        printf("Enqueue %d to Front Queue.",temp);
        arr[++END_FRONT] = temp;
    } else{
        if (END_BACK-1==END_FRONT || END_BACK-1 == -1){
            printf("Back Queue is Full!");
            return;
        }
        printf("Enqueue %d to Back Queue.",temp);
        arr[--END_BACK] = temp;
    }
}


void deleteItem(bool start){
    if (start){
        if (END_FRONT==-1){
            printf("Queue is Empty");
            return;
        }
        printf("Dequeue %d from Front Queue.",arr[0]);
        for(int i=0;i<END_FRONT;i++){
            arr[i] = arr[i+1];
        }
        END_FRONT--;
    } else{
        if (END_BACK==LENGTH){
            printf("Queue is Empty");
            return;
        }
        printf("Dequeue %d from Back Queue.",arr[LENGTH-1]);
        for(int i=LENGTH-1;i>END_BACK;i--){
            arr[i] = arr[i-1];
        }
        END_BACK++;
    }
}

void displayList(){
    printf("\nData: ");
    for(int i=0;i<LENGTH;i++){
        printf("%d ",arr[i]);
    }
    printf("\nFront Queue: START <- ");
    for(int i=0;i<END_FRONT+1;i++){
        printf("%d <- ",arr[i]);
    }
    printf("END");
    printf("\nEND Queue: START <- ");
    for(int i=LENGTH-1;i>=END_BACK;i--){
        printf("%d <- ",arr[i]);
    }
    printf("END");
}


int main() {
    int opt, temp;
    bool exe = true;
    while (exe){
        system("cls");
        printf("Double Queue - Abhinav Kumar\n");
        displayList();
        printf("\n\n1.Enqueue(Front)\n2.Enqueue(End)\n3.Dequeue(Front)"
               "\n4.Dequeue(End)\n5.Display\n0.Exit: ");
        scanf("%d",&opt);
        switch (opt){
            case 0:
                exe = false;
                break;
            case 1:
                printf("\nEnter an item to insert: ");
                scanf("%d",&temp);
                addItem(temp,true);
                break;
            case 2:
                printf("\nEnter an item to insert: ");
                scanf("%d",&temp);
                addItem(temp, false);
                break;
            case 3:
                deleteItem(true);
                break;
            case 4:
                deleteItem(false);
                break;
            case 5:
                displayList();
                break;
        }
        if (exe){
            getch();
        }
    }
    return 0;
}
