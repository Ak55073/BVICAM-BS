def cumulative_product(num_list, pos=0):
    if pos + 1 == len(num_list):
        return num_list[-1]
    num_list[pos + 1] = num_list[pos + 1] + num_list[pos]
    return cumulative_product(num_list, pos + 1)


if __name__ == '__main__':
    list_item = [5, 4, 3, 2, 5, 6, 7, 8]
    print(cumulative_product(list_item))
