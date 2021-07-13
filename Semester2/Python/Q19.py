def linear_search(search_list, item):
    pass_req = 1
    for i in range(0, len(search_list)):
        if search_list[i] == item:
            return i, pass_req
        pass_req += 1
    return -1, pass_req


def binary_search(search_list, item):
    pass_req = 1
    first = 0
    last = len(search_list)
    for i in range(0, int(len(search_list) / 2)):
        mid = int((first + last) / 2)
        if search_list[mid] == item:
            return mid, pass_req
        elif search_list[mid] > item:
            last = mid
        else:
            first = mid
        pass_req += 1
    return -1, pass_req


if __name__ == "__main__":
    item_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    number = int(input("Enter a number to search: "))

    position, pass_req = linear_search(item_list, number)
    print(f"Linear search found {number} at {position} with {pass_req} pass")

    position, pass_req = binary_search(item_list, number)
    print(f"Binary search found {number} at {position} with {pass_req} pass")
