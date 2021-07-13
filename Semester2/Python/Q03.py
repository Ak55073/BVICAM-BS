def find_result(num):
    return num if (num % 7 == 0 and num % 5 != 0) else None


if __name__ == '__main__':
    for i in range(1000, 2001):
        val = find_result(i)
        if val:
            print(val, end=" ")
