#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct node{
    int data;
    int priority;
    struct node *next;
};
typedef struct node NODE;
NODE *start;

void insertItem(int temp, int priority){
    NODE *nodePoint;
    int i = 1;
    nodePoint = (NODE*) malloc (sizeof(NODE));
    nodePoint->data = temp;
    nodePoint->priority = priority;
    nodePoint->next = NULL;

    if (start == NULL){
        printf("Enqueue %d",temp);
        start = nodePoint;
        return;
    }

    if (start->priority > priority){
        nodePoint -> next = start;
        start = nodePoint;
        return;
    }

    NODE *pos;
    pos = start;

    while(true){
        if (pos -> priority > priority || pos -> next == NULL){
            break;
        }
        pos = pos -> next;
        i++;
    }
    nodePoint -> next = pos -> next;
    pos -> next = nodePoint;
    printf("Enqueue %d",temp);
}

void deleteItem(){
    if (start == NULL){
        printf("\nList empty. No item deleted.");
        return;
    }
    NODE *pos;
    pos = start;
    start = start -> next;
    printf("\nDequeue from top: %d",pos->data);
    free(pos);
}

void displayList(){
    if (start == NULL){
        printf("\nLinklist: NULL");
        return;
    }

    NODE *pos;
    pos = start;
    printf("\nLinklist: START <- ");
    while(pos != NULL){
        printf("%d:%d <- ",pos -> data,pos -> priority);
        pos = pos -> next;
    }
    printf("END");
}

int main() {
    int temp, opt, pri;
    start = NULL;
    bool exe = true;
    printf("Priority Queue with Linear List - Abhinav Kumar\n\n");
    printf("1.Enqueue\n2.Dequeue\n3.Display\n0.Exit");
    while (exe){
        displayList();
        printf("\n: ");
        scanf("%d",&opt);
        switch (opt){
            case 0:
                exe = false;
                break;
            case 1:
                printf("Enter an item to insert: ");
                scanf("%d",&temp);
                printf("Enter Priority: ");
                scanf("%d",&pri);
                insertItem(temp, pri);
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
