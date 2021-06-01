def fibonacci(limit, i, j):
    num = i + j
    if num > limit:
        return
    print(", "+str(num), end="")
    i, j = j, num
    return fibonacci(limit, i, j)


if __name__ == '__main__':
    print("0, 1", end="")
    fibonacci(limit=50, i=0, j=1)
