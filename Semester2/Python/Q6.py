def print_set(num_list):
    for i in range(0, int(len(num_list) / 2)):
        print(num_list[i], end=" ")
    print()
    for i in range(int(len(num_list) / 2), len(num_list)):
        print(num_list[i], end=" ")


print_set((5, 4, 3, 2, 5, 6, 7))
