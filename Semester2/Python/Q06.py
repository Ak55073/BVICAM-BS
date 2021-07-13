def fibonacci(n, i, j):
    num = i + j
    if num > n:
        return
    print(", " + str(num), end="")
    return fibonacci(n, j, num)


if __name__ == '__main__':
    limit = int(input("Enter a limit: "))
    print("0, 1", end="")
    fibonacci(n=limit, i=0, j=1)
