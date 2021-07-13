#include <iostream>
using namespace std;

struct node{
    char key;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;
NODE *root;

NODE* addNode(){
    char item;
    NODE *nodePoint;
    nodePoint = (NODE*) malloc (sizeof(NODE));

    printf("Enter a item(. to exit): ");
    item = getchar();
    getchar();
    if (item=='.'){
        return NULL;
    }
    nodePoint -> key = item;

    printf("\nEnter a left child of %c\n",item);
    nodePoint -> left = addNode();
    printf("\nEnter a right child of %c\n",item);
    nodePoint -> right = addNode();

    return nodePoint;
}

void inorder_transversal(NODE* start){
    if (start!=NULL){
        inorder_transversal(start->left);
        printf("%c ",start->key);
        inorder_transversal(start->right);
    }
}

void preorder_transversal(NODE* start){
    if (start!=NULL){
        printf("%c ",start->key);
        preorder_transversal(start->left);
        preorder_transversal(start->right);
    }
}

void postorder_transversal(NODE* start){
    if (start!=NULL){
        postorder_transversal(start->left);
        postorder_transversal(start->right);
        printf("%c ",start->key);
    }
}

int main() {
    printf("Binary Tree [LinkedList] - Abhinav Kumar\n");

    root = addNode();

    printf("\nInorder  : ");
    inorder_transversal(root);

    printf("\nPreorder : ");
    preorder_transversal(root);

    printf("\nPostorder: ");
    postorder_transversal(root);

    return 0;
}
