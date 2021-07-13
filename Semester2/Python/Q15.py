def calculate_series(n, x):
    print("Series: ", end="")
    sum_series = 0
    for i in range(n):
        result = solve_series(i * 2, x)
        print(f"({round(result,3)})", end="")
        sum_series += result
    print(" =", round(sum_series,3))


def solve_series(i, x):
    if i > 0:
        print(" + " if i % 4 == 0 else " - ", end="")
    print(f"{x}^{i}/{i}!", end="")
    return ((x ** i) / factorial(i)) * (1 if i % 4 == 0 else -1)


def factorial(x, i=1, ans=1):
    return ans if i == x + 1 else factorial(x, i + 1, ans * i)


if __name__ == '__main__':
    limit = int(input("Enter value of n: "))
    value = int(input("Enter value of x: "))
    calculate_series(limit, value)
