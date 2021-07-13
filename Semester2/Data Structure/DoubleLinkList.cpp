#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
NODE *start,*last;

void additem(int temp){
    NODE *nodePoint;
    nodePoint = (NODE*) malloc (sizeof(NODE));
    nodePoint -> data = temp;

    if (start == NULL){
        nodePoint -> next = NULL;
        nodePoint -> prev = NULL;
        start = nodePoint;
        last = nodePoint;
    } else{
        nodePoint -> next = start;
        nodePoint -> prev = NULL;
        start -> prev = nodePoint;
        start = nodePoint;
    }
    printf("%d inserted at top(0)",temp);
}

void additemPosition(int temp, int index){
    if (start == NULL || index== 0){
        additem(temp);
        return;
    }

    NODE *nodePoint, *pos;
    nodePoint = (NODE*) malloc (sizeof(NODE));
    nodePoint -> data = temp;

    pos = start;
    int i = 0;
    while (true){
        i++;
        if (i>=index || pos->next==NULL){
            break;
        }
        pos = pos -> next;
    }
    if (pos -> next == NULL){
        last = nodePoint;
        nodePoint -> next = NULL;
        pos -> next = nodePoint;
        nodePoint -> prev = pos;
    } else{
        pos -> next -> prev = nodePoint;
        nodePoint -> next = pos -> next;
        pos -> next = nodePoint;
        nodePoint -> prev = pos;
    }
    printf("%d inserted at %d",temp,i);
}

void additemLast(int temp){
    if (start == NULL){
        additem(temp);
        return;
    }
    NODE *nodePoint;
    nodePoint = (NODE*) malloc (sizeof(NODE));
    nodePoint->data = temp;
    nodePoint->next = NULL;

    nodePoint-> prev = last;
    last -> next = nodePoint;
    last = nodePoint;


    printf("%d inserted at last",temp);
}

void deleteFirst(){
    if (start == NULL){
        printf("\nList empty. No item deleted.");
        return;
    }
    NODE *pos;
    pos = start;
    start = start -> next;
    start -> prev = NULL;
    printf("\nDeleting from top: %d",pos->data);
    free(pos);
}

void deletePosition(int index){
    if (start == NULL){
        printf("\nList empty. No item deleted.");
        return;
    } else if (index==0){
        deleteFirst();
        return;
    }

    NODE *pos, *temp;
    pos = start;
    int i = 0;
    while(true){
        i++;
        if (i >= index){
            break;
        }
        if (pos -> next == NULL){
            printf("\nInvalid postion. No item deleted.");
            return;
        }
        pos = pos -> next;
    }

    temp = pos -> next;
    if (pos -> next -> next == NULL) {
        pos -> next = NULL;
        last = pos;
    } else{
        temp -> next -> prev = pos;
        pos -> next = temp -> next;
    }
    printf("\nDeleting %d from %d",temp->data,i);
    free(temp);
}

void deleteLast(){
    if (last == NULL){
        printf("\nList empty. No item deleted.");
        return;
    }
    NODE *pos;
    pos = last;
    last = last -> prev;
    last -> next = NULL;
    printf("\nDeleting from top: %d",pos->data);
    free(pos);
}

void displayList(){
    if (start == NULL || last == NULL){
        printf("Linklist: NULL");
        return;
    }
    printf("Linklist");
    NODE *pos;
    pos = start;
    printf("\nSTART -> ");
    while(pos != NULL){
        printf("%d -> ",pos -> data);
        pos = pos -> next;
    }
    printf("END");

    pos = last;
    printf("\nEND -> ");
    while(pos != NULL){
        printf("%d -> ",pos -> data);
        pos = pos -> prev;
    }
    printf("START");
}

int main() {
    int temp, pos, opt;
    start = NULL;
    bool exe = true;
    while (exe){
        system("cls");
        printf("Double Linklist - Abhinav Kumar\n\n");
        displayList();
        printf("\n\n1.Add(Top)\n2.Add(Position)\n3.Add(Last)"
               "\n4.Delete(Top)\n5.Delete(Position)\n6.Delete(Last)"
               "\n7.Display List\n0.Exit: ");
        scanf("%d",&opt);
        switch (opt){
            case 0:
                exe = false;
                break;
            case 1:
                printf("\nEnter an item to insert: ");
                scanf("%d",&temp);
                additem(temp);
                break;
            case 2:
                printf("\nEnter an item to insert: ");
                scanf("%d",&temp);
                printf("Enter pos to insert: ");
                scanf("%d",&pos);
                additemPosition(temp,pos);
                break;
            case 3:
                printf("\nEnter an item to insert: ");
                scanf("%d",&temp);
                additemLast(temp);
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                printf("Enter pos to delete: ");
                scanf("%d",&pos);
                deletePosition(pos);
                break;
            case 6:
                deleteLast();
                break;
            case 7:
                displayList();
                break;
        }
        if (exe){
            getch();
        }
    }
    return 0;
}
