def print_set(num_list):
    for i in range(0, len(num_list)):
        print(num_list[i], end=" ")
        if i == int((len(num_list) / 2) - 1):
            print()


if __name__ == "__main__":
    num_set = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
    print_set(num_set)
