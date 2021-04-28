def factorial_generator(limit):
    product = 1
    for i in range(1, limit + 1):
        product *= i
        print('Factorial of', i, 'is', product)


if __name__ == '__main__':
    try:
        num = int(input("Enter a limit: "))
        factorial_generator(num)
    except ValueError:
        print("Only Integer value are accepted.")
