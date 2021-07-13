#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct node{
    int itemID;
    int itemQuantity;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
NODE *start,*last;

int getItem(int id){
    int quantity = 0;
    if (start == NULL){
        return -1;
    }

    NODE *pos = start;
    while(true){
        if (pos -> itemID == id){
            return pos -> itemQuantity;
        }
        if (pos -> next == NULL){
            return -1;
        }
        pos = pos -> next;
    }
}

void modifyItem(int id, int quantity, bool add){
    if (add){
        NODE *pos = start;
        while(true){
            if (pos -> itemID == id){
                pos -> itemQuantity += quantity;
                return;
            }
            pos = pos -> next;
        }
    } else {
        NODE *nodePoint;
        nodePoint = (NODE*) malloc (sizeof(NODE));
        nodePoint->itemID = id;
        nodePoint->itemQuantity = quantity;
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
}

void addWatch(){
    int id, itemQuantity, addQuantity;
    printf("Enter Item ID: ");
    scanf("%d",&id);
    itemQuantity = getItem(id);

    if (itemQuantity==-1){
        printf("Enter Item Quantity(New Item): ");
        scanf("%d",&addQuantity);
        modifyItem(id,addQuantity,false);
    } else {
        printf("Enter quantity to add: ");
        scanf("%d",&addQuantity);
        modifyItem(id,addQuantity,true);
    }
}

void deleteWatch(){
    int id, itemQuantity, removeQuantity;
    printf("Enter Item ID: ");
    scanf("%d",&id);
    itemQuantity = getItem(id);
    if (itemQuantity==-1){
        printf("Item not found!");
        return;
    } else {
        printf("Enter quantity to remove: ");
        scanf("%d",&removeQuantity);
        if (removeQuantity>itemQuantity){
            printf("Quantity exceeded.");
        } else{
            modifyItem(id,-removeQuantity,true);
        }
    }
}

void displayList(){
    if (start == NULL){
        printf("Database(ID:Quantity): NULL");
        return;
    }
    printf("Database(ID:Quantity): ");
    NODE *pos;
    pos = start;
    while(pos != NULL){
        printf("%d:%d,  ",pos->itemID,pos->itemQuantity);
        pos = pos -> next;
    }
    printf("\n");
}

int main() {
    int opt;
    start = NULL;
    last = NULL;
    bool exe = true;
    while (exe){
        system("cls");
        printf("Watch Store - Abhinav Kumar\n\n");
        displayList();
        printf("\n\n1.Add Watch\n2.Sell Watch\n3.Get Quantity"
               "\n4.Get Database\n0.Exit: ");
        scanf("%d",&opt);
        switch (opt){
            case 0:
                exe = false;
                break;
            case 1:
                addWatch();
                break;
            case 2:
                deleteWatch();
                break;
            case 3:
                int id, itemQuantity;
                printf("Enter Item ID: ");
                scanf("%d",&id);
                itemQuantity = getItem(id);
                if (itemQuantity==-1){
                    printf("Item ID:%d not in database.",id);
                } else{
                    printf("Item ID:%d has %d items.",id,itemQuantity);
                }
                break;
            case 4:
                displayList();
                break;
        }
        if (exe){
            getch();
        }
    }
    return 0;
}
