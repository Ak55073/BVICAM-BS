def bubble_sort(item_list):
    print(f"\nBubble sort on: {item_list}")
    for i in range(len(item_list)):
        for j in range(len(item_list) - 1):
            if item_list[j] > item_list[j + 1]:
                sortedFlag = False
                temp = item_list[j + 1]
                item_list[j + 1] = item_list[j]
                item_list[j] = temp
        print(f"List after pass {i + 1}: {item_list}")
        if item_list == sorted_array:
            break
    print("Sorted list: ", item_list)


def selection_sort(item_list):
    print(f"\n\nSelection sort on: {item_list}")
    for i in range(len(item_list)):
        least = i
        for j in range(i + 1, len(item_list)):
            if item_list[least] > item_list[j]:
                least = j
        if least != i:
            temp = item_list[least]
            item_list[least] = item_list[i]
            item_list[i] = temp
        print(f"List after pass {i + 1}: {item_list}")
        if item_list == sorted_array:
            break
    print("Sorted list: ", item_list)


def insertion_sort(item_list):
    print(f"\n\nInsertion sort on: {item_list}")
    for i in range(1, len(item_list)):
        key = item_list[i]
        j = i - 1
        while j >= 0 and key < item_list[j]:
            item_list[j + 1] = item_list[j]
            j -= 1
        item_list[j + 1] = key
        print(f"List after pass {i}: {item_list}")
        if item_list == sorted_array:
            break
    print("Sorted list: ", item_list)


def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]
        merge_sort(L)
        merge_sort(R)
        i = j = k = 0

        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1
    print(f"Sorting: {arr}")


sorted_array = [1, 2, 3, 3, 4, 5, 7, 8, 9]
if __name__ == "__main__":
    unsorted_list = [7, 3, 8, 3, 5, 1, 2, 9, 4]

    bubble_sort(list(unsorted_list))

    selection_sort(list(unsorted_list))

    insertion_sort(list(unsorted_list))

    print(f"\n\nMerge sort on: {unsorted_list}")
    merge_sort(unsorted_list)
    print("Sorted list: ", unsorted_list)