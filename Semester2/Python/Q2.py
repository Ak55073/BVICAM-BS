if __name__ == '__main__':
    x = lambda num: num if (num % 7 == 0 and num % 5 != 0) else None
    for i in range(1000, 2001):
        val = x(i)
        if val:
            print(val)
