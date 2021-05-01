def prime_generator(limit):
    print("Prime Numbers till", limit, "are: 1", end="")
    for i in range(2, limit + 1):
        prime = True
        for j in range(2, i):
            if i % j == 0:
                prime = False
        if prime:
            print(",", end="")
            print(i, end="")


if __name__ == '__main__':
    try:
        num = int(input("Enter a limit: "))
        prime_generator(num)
    except ValueError:
        print("Only Integer value are accepted.")
