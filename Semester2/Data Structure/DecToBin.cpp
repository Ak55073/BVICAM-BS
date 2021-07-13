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

void additemLast(int temp){
    NODE *nodePoint;
    nodePoint = (NODE*) malloc (sizeof(NODE));
    nodePoint->data = temp;
    if (start == NULL){
        nodePoint -> next = NULL;
        nodePoint -> prev = NULL;
        start = nodePoint;
        last = nodePoint;
        return;
    }
    nodePoint->next = NULL;
    nodePoint-> prev = last;
    last -> next = nodePoint;
    last = nodePoint;
}

void displayList(int temp){
    NODE *pos;
    pos = last;
    printf("Unsigned Binary equivalent to %d is: ",temp);
    while(pos != NULL){
        printf("%d",pos -> data);
        pos = pos -> prev;
    }
    printf("\n");
}


int main() {
    printf("Decimal to Binary - Abhinav Kumar\n");
    int decimal,temp;
    start = NULL;
    last = NULL;

    printf("Enter a decimal number: ");
    scanf("%d",&decimal);
    temp = decimal;

    while (decimal!=1){
        additemLast(decimal%2);
        decimal /= 2;
    }
    additemLast(1);
    displayList(temp);

    return 0;
}
