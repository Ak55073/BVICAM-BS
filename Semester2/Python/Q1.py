def fibonacci(limit, i, j, final):
    num = i + j
    if num > limit:
        return final
    if num % 2 == 0:
        final += num
    i, j = j, num
    return fibonacci(limit, i, j, final)


if __name__ == '__main__':
    print("Sum of fibonacci number:",
          fibonacci(limit=1000, i=0, j=1, final=0))
