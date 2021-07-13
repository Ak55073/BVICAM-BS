from random import randint


class MatrixManager:
    def __init__(self, m, n):
        self.matrix = [[None for i in range(n)] for j in range(m)]
        self.m = m
        self.n = n

    def change_value(self):
        x, y = input("Enter cord x,y: ").split(",")
        val = int(input("Enter value: "))
        self.matrix[int(x)][int(y)] = val

    def transpose_matrix(self):
        temp_matrix = [[None for i in range(self.n)] for j in range(self.m)]
        for i in range(self.m):
            for j in range(self.n):
                temp_matrix[i][j] = self.matrix[(self.m - i) - 1][(self.n - j) - 1]
        self.matrix = temp_matrix
        print("Matrix Transposed!")

    def row_wise_sum(self):
        for i in range(self.m):
            print(f"Row {i}: ", end="")
            sum_row = 0
            for j in self.matrix[i]:
                if sum_row != 0:
                    print(" + ", end="")
                print("%02d " % (j,), end="")
                sum_row += j
            print(f" = {sum_row}")

    def column_wise_sum(self):
        for i in range(self.n):
            print(f"Column {i}: ", end="")
            sum_column = 0
            for j in range(self.m):
                if sum_column != 0:
                    print(" + ", end="")
                print("%02d " % (self.matrix[j][i],), end="")
                sum_column += self.matrix[j][i]
            print(f" = {sum_column}")

    def diagonal_wise_sum(self):
        print(f"Diagonal sum: ", end="")
        sum_diagonal = 0
        for i in range(self.m if self.m <= self.n else self.n):
            if sum_diagonal != 0:
                print(" + ", end="")
            print("%02d " % (self.matrix[i][i],), end="")
            sum_diagonal += self.matrix[i][i]
        print(f" = {sum_diagonal}")

    def triangular_matrix(self, upper=True):
        print("\nUpper Triangular Matrix:")
        for i in range(self.m):
            for j in range(self.n):
                if self.matrix[i][j] is not None:
                    if upper:
                        print("%02d " % (self.matrix[i][j] if i <= j else 0,), end="")
                    else:
                        print("%02d " % (self.matrix[i][j] if j <= i else 0,), end="")
                else:
                    print("-- ", end="")
            print()

    def random_data(self):
        for i in range(self.m):
            for j in range(self.n):
                self.matrix[i][j] = randint(1, 99)

    def print_matrix(self):
        print("\nMatrix:")
        for i in range(self.m):
            for j in range(self.n):
                if self.matrix[i][j] is not None:
                    print("%02d " % (self.matrix[i][j],), end="")
                else:
                    print("-- ", end="")
            print()


if __name__ == "__main__":
    matrix = MatrixManager(5, 5)

    while True:
        inp = int(input("""\nSelect
1. Change Value
2. Transpose Matrix
3. Row-wise sum
4. Column-wise sum
5. Sum of diagonal element
6. Upper Triangular matrix
7. Lower Triangular matrix
8. Display matrix
9. Fill Random data
10. Exit: """))
        if inp == 1:
            matrix.change_value()
        elif inp == 2:
            matrix.transpose_matrix()
        elif inp == 3:
            matrix.row_wise_sum()
        elif inp == 4:
            matrix.column_wise_sum()
        elif inp == 5:
            matrix.diagonal_wise_sum()
        elif inp == 6:
            matrix.triangular_matrix()
        elif inp == 7:
            matrix.triangular_matrix(upper=False)
        elif inp == 8:
            matrix.print_matrix()
        elif inp == 9:
            matrix.random_data()
        elif inp == 10:
            break
        else:
            continue
