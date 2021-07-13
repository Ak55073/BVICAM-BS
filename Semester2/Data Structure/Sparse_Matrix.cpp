#include <iostream>

using namespace std;
const int ROWS = 4;
const int COLUMNS = 4;

void sparseMatrix(int matrix[ROWS][COLUMNS]){
    int non_zero = 0;
    for (int i=0;i<ROWS;i++){
        for (int j=0;j<COLUMNS;j++){
            if (matrix[i][j]!=0){
                non_zero++;
            }
        }
    }

    if (non_zero > ((ROWS+COLUMNS))) {
        printf("Matrix isn't sparse matrix");
        return;
    }

    int pos = 0;
    int sparseMatrix[3][non_zero];
    for (int i=0;i<ROWS;i++){
        for (int j=0;j<COLUMNS;j++){
            if (matrix[i][j]>0){
                sparseMatrix[0][pos] = i;
                sparseMatrix[1][pos] = j;
                sparseMatrix[2][pos] = matrix[i][j];
                pos++;
            }
        }
    }

    printf("ROW\tCOLUMN\tValue\n");
    for (int i=0;i<non_zero;i++){
        printf("%d\t%d\t%d\n",sparseMatrix[0][i],
               sparseMatrix[1][i],sparseMatrix[2][i]);
    }
}

int main() {
    printf("Sparse Matrix - Abhinav Kumar\n\n");
    int matrix[ROWS][COLUMNS] = {0};
    for (int i=0;i<ROWS;i++){
        for (int j=0;j<COLUMNS;j++){
            printf("Enter value[%d][%d]: ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    sparseMatrix(matrix);
    return 0;
}
