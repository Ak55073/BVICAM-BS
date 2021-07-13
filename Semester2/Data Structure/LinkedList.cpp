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

void additem(int temp){
    NODE *nodePoint;
    nodePoint = (NODE*) malloc (sizeof(NODE));
    nodePoint -> data = temp;

    if (start == NULL){
        nodePoint -> next = NULL;
        start = nodePoint;
    } else{
        nodePoint -> next = start;
        start = nodePoint;
    }
    printf("%d inserted at top(0)",temp);
}

void additemPosition(int temp, int index){
    NODE *nodePoint;
    nodePoint = (NODE*) malloc (sizeof(NODE));
    nodePoint -> data = temp;

    if (start == NULL){
        start = nodePoint;
        nodePoint -> next = NULL;
        printf("%d inserted at top(0) - list empty",temp);
        return;
    } else if (index==0){
        nodePoint -> next = start;
        start = nodePoint;
        printf("%d inserted at 0",temp);
        return;
    }

    NODE *pos;
    pos = start;
    int i = 0;
    while (true){
        i++;
        if (i>=index || pos->next==NULL){
            break;
        }
        pos = pos -> next;
    }
    nodePoint -> next = pos -> next;
    pos -> next = nodePoint;
    printf("%d inserted at %d",temp,i);
}

void additemLast(int temp){
    NODE *nodePoint;
    int i = 1;
    nodePoint = (NODE*) malloc (sizeof(NODE));
    nodePoint->data = temp;
    nodePoint->next = NULL;

    if (start == NULL){
        printf("%d inserted at last(0)",temp);
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
    printf("%d inserted at last(%d)",temp,i);
}

void deleteFirst(){
    if (start == NULL){
        printf("\nList empty. No item deleted.");
        return;
    }
    NODE *pos;
    pos = start;
    start = start -> next;
    printf("\nDeleting from top: %d",pos->data);
    free(pos);
}

void deletePosition(int index){
    if (start == NULL){
        printf("\nList empty. No item deleted.");
        return;
    } else if (index==0){
        NODE *pos;
        pos = start;
        if (start -> next == NULL){
            start = NULL;
        } else{
            start = start -> next;
        }
        printf("\nDeleting %d from 0",pos->data);
        free(pos);
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
    printf("\nDeleting %d from %d",temp->data,i);
    if (pos -> next -> next == NULL) {
        pos -> next = NULL;
    } else{
        pos -> next = pos -> next -> next;
    }
    free(temp);
}

void deleteLast(){
    if (start == NULL){
        printf("\nList empty. No item deleted.");
        return;
    } else if (start->next==NULL){
        NODE *pos;
        pos = start;
        start = NULL;
        printf("\nDeleting from last: %d",pos->data);
        free(pos);
    } else {
        NODE *pos,*item;
        pos = start;
        while(pos -> next -> next != NULL){
            pos = pos -> next;
        }
        item = pos -> next;
        pos -> next = NULL;
        printf("\nDeleting from last: %d",item->data);
        free(item);
    }
}

void searchList(int data){
    NODE *pos;
    pos = start;
    if (pos == NULL){
        return;
    }
    int i = 0;
    while(pos!=NULL){
        i++;
        if (pos->data==data){
            printf("\nFound %d at %d\n",data,i-1);
            return;
        } else {
            pos = pos -> next;
        }
    }
    printf("\n%d Not Found\n",data);
}

void searchListPos(int index){
    NODE *pos;
    pos = start;
    if (pos == NULL){
        return;
    }
    int i = 0;
    while(i<index){
        i++;
        if (pos -> next==NULL){
            printf("\nNothing found at %d\n",index);
            return;
        }
        pos = pos -> next;
    }
    printf("\nData at %d: %d\n",index,pos->data);
}

void displayList(){
    if (start == NULL){
        printf("Linklist: NULL");
        return;
    }

    NODE *pos;
    pos = start;
    printf("Linklist: START -> ");
    while(pos != NULL){
        printf("%d -> ",pos -> data);
        pos = pos -> next;
    }
    printf("END");
}

void remove_duplicates(){
    if (start == NULL){
        printf("List is empty!");
        return;
    }

    NODE *pos;
    pos = start;
    int i = 0;
    while (pos->next!=NULL){
        NODE *sub;
        sub = pos -> next;
        bool found = false;

        while (sub!=NULL){
            if (sub->data==pos->data){
                found = true;
                break;
            } else {
                sub = sub -> next;
            }
        }
        pos = pos -> next;
        if (found){
            deletePosition(i);
        } else{
            i++;
        }
    }
}

void deleteWholeList(){
    if (start == NULL){
        printf("\nList empty. No item deleted.");
        return;
    }

    while (start!=NULL){
        NODE *pos = start;
        start = start -> next;
        free(pos);

    }
    printf("\nAll data in linked list wiped.");
}

int main() {
    int temp, pos, opt;
    start = NULL;
    bool exe = true;
    while (exe){
        system("cls");
        printf("Linear Linklist - Abhinav Kumar\n\n");
        displayList();
        printf("\n\n01.Add(Top)\n02.Add(Position)\n03.Add(Last)\n04.Delete(Top)"
               "\n05.Delete(Position)\n06.Delete(Last)\n07.Search Item(with data)"
               "\n08.Search Item(with pos)\n09.Delete linklist"
               "\n10.Display List\n11.Remove Duplicates\n00.Exit: ");
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
                printf("\nEnter item to search: ");
                scanf("%d",&temp);
                searchList(temp);
                break;
            case 8:
                printf("\nEnter pos to search: ");
                scanf("%d",&pos);
                searchListPos(pos);
                break;
            case 9:
                deleteWholeList();
                break;
            case 10:
                displayList();
                break;
            case 11:
                remove_duplicates();
                break;
        }
        if (exe){
            getch();
        }
    }
    return 0;
}
