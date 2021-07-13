#include <iostream>
#include <conio.h>

using namespace std;
const int LENGTH = 4;
int arr[LENGTH] = {0};
int START=-1;
int END=-1;

void addItem(int temp){
    if (START==-1){
        arr[0] = temp;
        START = 0;
        END = 0;
        return;
    }

    if ((START==0 && END+1==LENGTH) || END+1==START){
        printf("Queue is full");
        return;
    }

    if (END+1==LENGTH){
        END = 0;
        arr[0] = temp;
        return;
    }
    arr[++END] = temp;
}

void deleteItem(){
    if (START==-1){
        printf("Empty!");
        return;
    }

    if (START==END){
        START = -1;
        END = -1;
        return;
    }

    if (START==LENGTH){
        START = 0;
    } else{
        START++;
    }
}

void displayList(){
    int i;
    printf("START %d - END %d",START,END);
    printf("\nData: ");

    if (START==-1){
        printf("Empty!");
        return;
    }

    for(int i=0;i<LENGTH;i++){
        printf("%d ",arr[i]);
    }

    printf("\nQueue: ");
    if (END >= START){
        for(int i=START;i<END+1;i++){
            printf("%d ",arr[i]);
        }
    } else{
        for(int i=START;i<LENGTH;i++){
            printf("%d ",arr[i]);
        }
        for(int i=0;i<END+1;i++){
            printf("%d ",arr[i]);
        }
    }

}

int main() {
    int opt, temp;
    bool exe = true;
    while (exe){
        system("cls");
        printf("Circular LinkList - Abhinav Kumar\n\n");
        displayList();
        printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\n0.Exit: ");
        scanf("%d",&opt);
        switch (opt){
            case 0:
                exe = false;
                break;
            case 1:
                printf("\nEnter an item to insert: ");
                scanf("%d",&temp);
                addItem(temp);
                break;
            case 2:
                deleteItem();
                break;
            case 3:
                displayList();
                break;
        }
        if (exe){
            getch();
        }
    }
    return 0;
}
