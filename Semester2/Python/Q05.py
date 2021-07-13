def reverse_list(num_list):
    return [num_list[i] for i in range(len(num_list) - 1, -1, -1)]


if __name__ == '__main__':
    list_item = [5, 4, 3, 2, 5, 6, 7]
    print(reverse_list(num_list=list_item))
