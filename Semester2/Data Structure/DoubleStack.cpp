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
            printf("Front stack is full!");
            return;
        }
        printf("Pushed %d from front stack.",temp);
        arr[++END_FRONT] = temp;
    } else{
        if (END_BACK-1==END_FRONT || END_BACK-1 == -1){
            printf("Back stack is full!");
            return;
        }
        printf("Pushed %d from back stack.",temp);
        arr[--END_BACK] = temp;
    }
}


void deleteItem(bool start){
    if (start){
        if (END_FRONT==-1){
            printf("Front stack is Empty!");
            return;
        }
        printf("Poped %d to front stack.",arr[END_FRONT--]);
    } else{
        if (END_BACK==LENGTH){
            printf("Back stack is Empty!");
            return;
        }
        printf("Poped %d to back stack.",arr[END_BACK++]);
    }
}

void displayList();

int main() {
    int opt, temp;
    bool exe = true;
    while (exe){
        system("cls");
        printf("Double Stack - Abhinav Kumar\n");
        displayList();
        printf("\n\n1.Push(Front)\n2.Push(End)\n"
               "3.Pop(Front)\n4.Pop(End)\n5.Display\n0.Exit: ");
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

void displayList(){
    printf("\nData: ");
    for(int i=0;i<LENGTH;i++){
        printf("%d ",arr[i]);
    }
    printf("\nFront Stack: END <- ");
    for(int i=0;i<END_FRONT+1;i++){
        printf("%d <- ",arr[i]);
    }
    printf("START");
    printf("\nEND Stack: END <- ");
    for(int i=LENGTH-1;i>=END_BACK;i--){
        printf("%d <-",arr[i]);
    }
    printf("START");
}
