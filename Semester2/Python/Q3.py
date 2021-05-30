def cumulative_product(num_list, pos):
    if pos + 1 == len(num_list):
        return num_list[-1]
    num_list[pos + 1] = num_list[pos + 1] + num_list[pos]
    return cumulative_product(num_list, pos + 1)


print(cumulative_product([5, 4, 3, 2, 5, 6, 7], 0))
