#include <iostream>
#include <math.h>
using namespace std;

const int LENGTH = 10;
int tree[LENGTH];

void root(int x){
    if (tree[0]==0){
        tree[0] = x;
    } else {
        printf("Root already exist.\n");
    }
}

void left(int x, int par){
    if(tree[par] != 0){
        tree[(2*par)+1]=x;
    } else {
        printf("Parent %d does not exist.\n",par);
    }
}

void right(int x, int par){
    if(tree[par] != 0){
        tree[(2*par)+2]=x;
    } else {
        printf("Parent %d does not exist.\n",par);
    }
}

void preorder(){
    printf("\nTree: ");
    for (int i=0;i<LENGTH;i++){
        printf("%d ",tree[i]);
    }
}

int main(){
    int node, parent, left_child, right_child;
    printf("Binary Tree [Stack] - Abhinav Kumar\n\n");
    root(11);
    right(13,0);
    left(12,0);
    right(15,1);
    left(14,2);
    preorder();

    printf("\nEnter ith node: ");
    scanf("%d", &node);

    if (node != 0){
        parent = floor((node-1)/2);
        printf("\nParent of %d: %d",tree[node],tree[parent]);
    } else{
        printf("\n%d is root.",tree[node]);
    }

    left_child = (2*node) + 1;
    if (left_child < LENGTH && tree[left_child] != 0) {
        printf("\nLeft Child of %d: %d",tree[node],tree[left_child]);
    } else {
        printf("\n%d has no Left Child",tree[node]);
    }

    right_child = (2*node) + 2;
    if (right_child < LENGTH && tree[right_child] != 0) {
        printf("\nRight Child of %d: %d\n",tree[node],tree[right_child]);
    } else {
        printf("\n%d has no Right Child\n",tree[node]);
    }

    return 1;
}
