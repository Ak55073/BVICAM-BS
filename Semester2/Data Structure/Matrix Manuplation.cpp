#include <iostream>

using namespace std;
const int ROWS = 4;
const int COLUMNS = 4;

void sumRowCol(int matrix[ROWS][COLUMNS], bool row){
    if (row){
        for (int i=0;i<ROWS;i++){
            int sum =0;
            for (int j=0;j<COLUMNS;j++){
                sum = sum + matrix[i][j];
            }
            printf("Sum of Row %d is %d \n" ,i,sum);
        }
    } else {
        for (int i=0;i<COLUMNS;i++){
            int sum =0;
            for (int j=0;j<ROWS;j++){
                sum = sum + matrix[j][i];
            }
            printf("Sum of Col %d is %d \n" ,i,sum);
        }
    }
}

void sumDiagonal(int matrix[ROWS][COLUMNS]){
    int sum = 0;
    int temp_matrix[ROWS][COLUMNS] = {0};
    for (int i=0;i<ROWS;i++){
        sum = sum + matrix[i][i];
        temp_matrix[i][i] = matrix[i][i];
    }

    for (int i=0;i<ROWS;i++){
        for (int j=0;j<COLUMNS;j++){
            printf("%d ",temp_matrix[i][j]);
        }
        printf("\n");
    }
    printf("Sum of Diagonal= %d",sum);
}

void sumAll(int matrix[ROWS][COLUMNS]){
    int sum =0;
    for (int i=0;i<ROWS;i++){
        for (int j=0;j<COLUMNS;j++){
            sum = sum + matrix[i][j];
        }
    }
    printf("Sum of all elements= %d",sum);
}

void sumTriangularMatrix(int matrix[ROWS][COLUMNS], bool upper){
    int sum =0;
    int temp_matrix[ROWS][COLUMNS];
    for (int i=0;i<ROWS;i++){
        for (int j=0;j<COLUMNS;j++){
            if((upper && i<=j) || (!upper && i>=j)){
                sum = sum + matrix[i][j];
                temp_matrix[i][j] = matrix[i][j];
            } else{
                temp_matrix[i][j] = 0;
            }
        }
    }
    for (int i=0;i<ROWS;i++){
        for (int j=0;j<COLUMNS;j++){
            printf("%d ",temp_matrix[i][j]);
        }
        printf("\n");
    }
    printf("Sum of %s Triangular Matrix = %d\n",(upper? "Upper" : "Lower"),sum);
}

void transposeMatrix(int matrix[ROWS][COLUMNS]){
    printf("Transpose of Matrix:\n");
    for (int i=0;i<ROWS;i++){
        for (int j=0;j<COLUMNS;j++){
            printf("%d ",matrix[j][i]);
        }
        printf("\n");
    }
}

int main() {
    printf("Matrix Manipulation - Abhinav Kumar\n\n");
    int matrix[ROWS][COLUMNS] = { 0 };

    // Taking input(matrix)
    for (int i=0;i<ROWS;i++){
        for (int j=0;j<COLUMNS;j++){
            printf("Enter value[%d][%d]: ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    for (int i=0;i<ROWS;i++){
        for (int j=0;j<COLUMNS;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Matrix Sums
    sumRowCol(matrix,true);
    printf("\n");
    sumRowCol(matrix,false);
    printf("\n");
    sumAll(matrix);
    printf("\n\n");

    // Matrix Operations
    sumDiagonal(matrix);
    printf("\n\n");
    sumTriangularMatrix(matrix, true);
    printf("\n");
    sumTriangularMatrix(matrix, false);
    printf("\n");
    transposeMatrix(matrix);

    return 0;
}
