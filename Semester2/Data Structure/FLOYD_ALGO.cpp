#include <iostream>

using namespace std;
const int LENGTH = 8;
int cost_matrix[LENGTH][LENGTH] = {
    {999,200,999,999,999,400,350,999},
    {200,999,450,999,999,999,240,999},
    {999,450,250,999,999,999,999,200},
    {999,999,250,999,300,999,999,230},
    {999,999,999,300,999,280,999,520},
    {400,999,999,999,280,999,150,999},
    {350,240,999,999,999,150,999,199},
    {999,999,200,230,520,999,199,999}
};
int path[LENGTH][LENGTH] = {
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1}
};

void path_func(int i, int j){
    int k;
    k = path[i][j];
    if (k==-1){
        printf(" -> ");
        return;
    }
    path_func(i,k);
    printf("%d", k);
    path_func(k,j);
}

int main() {
    int temp;
    printf("Floyd Warshall - Abhinav Kumar\n\n");

    for(int k=0;k<LENGTH;k++){
        for(int i=0;i<LENGTH;i++){
            for(int j=0;j<LENGTH;j++){
                temp = cost_matrix[i][k] + cost_matrix[k][j];
                if (cost_matrix[i][j] > temp) {
                    cost_matrix[i][j] = temp;
                    path[i][j] = k;
                }
            }
        }
    }

    printf("Cost Matrix: \n");
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<LENGTH;j++){
            printf("%2d ",cost_matrix[i][j]);
        }
        printf("\n");
    }


    printf("\nFrom\tTo\tCost\tPath\n\n");
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<LENGTH;j++){
            printf("%2d\t%2d\t%2d\t",i,j,cost_matrix[i][j]);
            printf("%d",i);
            path_func(i,j);
            printf("%d\n", j);
        }
        printf("\n");
    }

    return 0;
}
