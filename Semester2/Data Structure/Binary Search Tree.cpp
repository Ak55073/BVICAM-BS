#include <iostream>
#include <conio.h>
using namespace std;

struct node{
    char key;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;

NODE* insertNode(NODE *rootNode, int x){
    NODE *nodePoint;
    nodePoint = (NODE*) malloc (sizeof(NODE));
    nodePoint->key = x;
    nodePoint->left = NULL;
    nodePoint->right = NULL;
    if (rootNode==NULL){
        return nodePoint;
    }

    if (x<rootNode->key){
        rootNode->left = insertNode(rootNode->left,x);
    } else if (x>rootNode->key) {
         rootNode->right = insertNode(rootNode->right,x);
    }
    return rootNode;
}

void inorder(NODE *rootNode){
    if(rootNode) {
        inorder(rootNode->left);
        printf("%d ",rootNode->key);
        inorder(rootNode->right);
    }
}

void postorder(NODE *rootNode){
    if(rootNode) {
        postorder(rootNode->left);
        postorder(rootNode->right);
        printf("%d ",rootNode->key);
    }
}

void preorder(NODE *rootNode){
    if(rootNode) {
        printf("%d ",rootNode->key);
        preorder(rootNode->left);
        preorder(rootNode->right);
    }
}

int minNode(NODE *rootNode){
    if (rootNode->left != NULL){
        return minNode(rootNode->left);
    }
    return rootNode->key;
}

int maxNode(NODE *rootNode){
    if (rootNode->right != NULL){
        return maxNode(rootNode->right);
    }
    return rootNode->key;
}

int heightTree(NODE *rootNode){
    if (rootNode == NULL){
        return -1;
    }

    int left_height = heightTree(rootNode->left);
    int right_height = heightTree(rootNode->right);

    if (left_height > right_height) {
        return left_height + 1;
    } else {
        return right_height + 1;
    }
}

int countNodes(NODE *rootNode){
    if (rootNode == NULL){
        return 1;
    }
    return countNodes(rootNode->left) + countNodes(rootNode->right);
}

int countLeafNodes(NODE *rootNode){
    if(rootNode == NULL){
        return 0;
    }

    if(rootNode->left == NULL && rootNode->right == NULL){
        return 1;
    } else {
        return (countLeafNodes(rootNode->left) + countLeafNodes(rootNode->right));
    }

}

NODE *searchNode(NODE *rootNode, int item){
    if (item==rootNode->key){
        return rootNode;
    } else if ( item < rootNode->key ){
        if (rootNode->left==NULL){
            return NULL;
        }
        return searchNode(rootNode->left, item);
    } else {
        if (rootNode->right==NULL){
            return NULL;
        }
        return searchNode(rootNode->right, item);
    }
}

int main(){
    int node, opt;
    NODE *root = NULL;
    bool exe=true;
    printf("Binary Search Tree [LinkedList] - Abhinav Kumar\n");
    printf("\n1. Insert Node\n2. Pre-Order Transversal\n3. In-Order Transversal\n"
           "4. Post-Order Transversal\n5. Height of tree\n6. Find smallest node\n"
           "7. Find largest node\n8. Search Node\n9. Total number of nodes\n10. No. of leaf nodes\n"
           "0.Exit\n");
    while (exe){
        printf("\nBST (In-order): ");
        inorder(root);
        printf("\nEnter: ");
        scanf("%d",&opt);
        switch (opt){
            case 0:
                exe = false;
                break;
            case 1:
                printf("Enter node: ");
                scanf("%d", &node);
                root = insertNode(root,node);
                break;
            case 2:
                printf("Preorder transversal: ");
                preorder(root);
                break;
            case 3:
                printf("Inorder transversal: ");
                inorder(root);
                break;
            case 4:
                printf("Postorder transversal: ");
                postorder(root);
                break;
            case 5:
                printf("Height of tree is: %d", heightTree(root));
                break;
            case 6:
                printf("Min Node: %d",minNode(root));
                break;
            case 7:
                printf("Max Node: %d",maxNode(root));
                break;
            case 8:
                printf("Enter node to search: ");
                scanf("%d", &node);
                if (searchNode(root,node)==NULL){
                    printf("Node Not found");
                } else {
                    printf("Node found");
                }
                break;
            case 9:
                printf("Total number of nodes: %d",  countNodes(root)-1);
                break;
            case 10:
                printf("Total number of Leaf nodes: %d",
                       countLeafNodes(root));
                break;
        }
        if (exe){
            getch();
        }
    }
    return 0;
}
