#include <iostream>

using namespace std;

struct node{
    char key;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;
NODE *root;

NODE* addNode(char temp){
    NODE *nodePoint;
    nodePoint = (NODE*) malloc (sizeof(NODE));
    nodePoint -> key = temp;
    nodePoint -> right = NULL;
    nodePoint -> left = NULL;
    return nodePoint;
}

int tree_height(NODE* root) {
    if (!root)
        return 0;
    else {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

void print_level(NODE* root, int level_no) {
    if (!root)
        return;
    if (level_no == 0) {
        printf("-> %c  ", root-> key);
    }
    else {
        print_level(root->left, level_no - 1);
        print_level(root->right, level_no - 1);
    }

}

void print_tree_level_order(NODE* root) {
    if (!root)
        return;
    int height = tree_height(root);

    printf("\nLevel Order Traversal: ");
    for (int i=0; i<height; i++) {
        print_level(root, i);
    }
    printf("\n");
}

int main() {
    printf("Binary Tree [LinkedList] - Abhinav Kumar\n");

    // Static implementation
    root = addNode('A');
    root -> left = addNode('B');
    root -> right = addNode('H');
    root -> left -> left = addNode('I');
    root -> left -> right = addNode('N');
    root -> right -> left = addNode('A');
    root -> right -> right = addNode('V');

    print_tree_level_order(root);

    return 0;
}
