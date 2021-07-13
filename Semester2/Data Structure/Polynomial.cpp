#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct node{
    int coefficient;
    int power;
    struct node *next;
};

typedef struct node NODE;
NODE *var1,*var2,*solv;

void additemLast(NODE** var,int coff,int pow){
    NODE *nodePoint;
    int i = 1;
    nodePoint = (NODE*) malloc (sizeof(NODE));
    nodePoint->coefficient = coff;
    nodePoint->power = pow;
    nodePoint->next = NULL;

    if ((*var) == NULL){
        (*var) = nodePoint;
        return;
    }

    NODE *pos;
    pos = (*var);

    while(pos -> next!=NULL){
        pos = pos -> next;
        i++;
    }
    pos -> next = nodePoint;
}

void displayList(){
    if (var1 == NULL){
        printf("Polynomial 1: Empty");
    } else {
        NODE *pos;
        pos = var1;
        printf("Polynomial 1: ");
        while(pos != NULL){
            printf("%dx^%d",pos -> coefficient,pos -> power);
            pos = pos -> next;
            if (pos!=NULL){
                printf(" + ");
            }
        }
    }

    if (var2 == NULL){
        printf("\nPolynomial 2: Empty\n");
    } else{
        NODE *pos;
        pos = var2;
        printf("\nPolynomial 2: ");
        while(pos != NULL){
            printf("%dx^%d",pos -> coefficient,pos -> power);
            pos = pos -> next;
            if (pos!=NULL){
                printf(" + ");
            }
        }
    }
}

void displayAns(){
    if (solv == NULL){
        printf("Answer: Empty");
    } else {
        NODE *pos;
        pos = solv;
        printf("\nAnswer: ");
        while(pos != NULL){
            printf("%dx^%d",pos -> coefficient,pos -> power);
            pos = pos -> next;
            if (pos!=NULL){
                printf(" + ");
            }
        }
        printf("\n");
    }
}

void sum_matrix(){
    int highest_power,sum;
    if (var1 == NULL || var2 == NULL){
        return;
    }
    NODE *pos1,*pos2;
    pos1 = var1;
    pos2 = var2;
    highest_power = pos1->power > pos2->power ? pos1->power : pos2->power;
    for(int i=highest_power;i>0;i--){
        sum=0;
        if (pos1 -> power == i){
            sum = sum + pos1 -> coefficient;
            pos1 = pos1 -> next;
        }
        if (pos2 -> power == i){
            sum = sum + pos2 -> coefficient;
            pos2 = pos2 -> next;
        }
        additemLast(&solv,sum,i);
    }
    displayAns();
}

int main() {
    printf("Polynomail Addition - Abhinav Kumar\n");
    int coff, pow, opt;
    var1 = NULL;
    var2 = NULL;

    bool exe = true;
    while (exe){
        system("cls");
        displayList();
        printf("\n\nPolynomial 1\n1.Extend\n2.Next: " );
        scanf("%d",&opt);
        switch (opt){
            case 1:
                printf("\nEnter coefficient: ");
                scanf("%d",&coff);
                printf("Enter power: ");
                scanf("%d",&pow);
                additemLast(&var1,coff,pow);
                break;
            case 2:
                exe = false;
                break;
        }
    }


    exe = true;
    while (exe){
        system("cls");
        displayList();
        printf("\n\nPolynomial 2\n1.Extend\n2.Add Polynomials: " );
        scanf("%d",&opt);
        switch (opt){
            case 1:
                printf("\nEnter coefficient: ");
                scanf("%d",&coff);
                printf("Enter power: ");
                scanf("%d",&pow);
                additemLast(&var2,coff,pow);
                break;
            case 2:
                exe = false;
                break;
        }
    }

    sum_matrix();

    return 0;
}
