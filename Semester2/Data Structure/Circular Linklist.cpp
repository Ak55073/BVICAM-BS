#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct node{
    char data[10];
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
NODE *start,*last;


void additemLast(char temp[]){
    NODE *nodePoint;
    nodePoint = (NODE*) malloc (sizeof(NODE));
    strcpy(nodePoint -> data, temp);
    if (start == NULL){
        nodePoint -> next = start;
        nodePoint -> prev = NULL;
        start = nodePoint;
        last = nodePoint;
        return;
    }
    nodePoint-> next = start;
    nodePoint-> prev = last;
    last -> next = nodePoint;
    last = nodePoint;
}

void deleteFirst(){
    if (start == NULL){
        return;
    }
    if (start -> next == start){
        NODE *pos;
        pos = start;
        start = NULL;
        last = NULL;
        free(pos);
    } else{
        NODE *pos;
        pos = start;
        last -> next = start -> next;
        start = start -> next;
        start -> prev = NULL;
        free(pos);
    }
}

void displayList(){
    if (start == NULL || last == NULL){
        return;
    }
    NODE *pos;
    pos = start;
    do {
        printf("%s ",pos -> data);
        pos = pos -> next;
    } while(pos->data != start->data);
    printf("\n");
}

int main() {
    start = NULL;
    last = NULL;

    printf("Circular Linklist - Abhinav Kumar\n\n");

    additemLast("i");
    additemLast("think");
    additemLast("i");
    additemLast("can");
    displayList();

    for(int i=0;i<4;i++){
        deleteFirst();
        displayList();
    }

    return 0;
}
