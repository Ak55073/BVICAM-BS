def reverse_list(num_list):
    return [num_list[i] for i in range(len(num_list) - 1, -1, -1)]


print(reverse_list([5, 4, 3, 2, 5, 6, 7]))
