#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct node{
    int data;
    struct node *next;
};

typedef struct node NODE;
NODE *start;

void additemLast(int temp){
    NODE *nodePoint;
    int i = 1;
    nodePoint = (NODE*) malloc (sizeof(NODE));
    nodePoint->data = temp;
    nodePoint->next = NULL;

    if (start == NULL){
        printf("Enqueue %d",temp);
        start = nodePoint;
        return;
    }

    NODE *pos;
    pos = start;

    while(pos -> next!=NULL){
        pos = pos -> next;
        i++;
    }
    pos -> next = nodePoint;
    printf("Enqueue %d",temp);
}

void deleteFirst(){
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
        printf("Linklist: NULL");
        return;
    }

    NODE *pos;
    pos = start;
    printf("Linklist: START <- ");
    while(pos != NULL){
        printf("%d <- ",pos -> data);
        pos = pos -> next;
    }
    printf("END");
}

int main() {
    int temp, opt;
    start = NULL;
    bool exe = true;
    while (exe){
        system("cls");
        printf("Queue with Linear List - Abhinav Kumar\n\n");
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
                additemLast(temp);
                break;
            case 2:
                deleteFirst();
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
