def count_item(data, item):
    if item in data.keys():
        data[item] += 1
    else:
        data[item] = 1


def combine_lists(li1, li2, li3):
    data = dict()
    highest = max([len(li1), len(li2), len(li3)])
    for i in range(highest):
        if li1[i]:
            count_item(data, li1[i])
        if i < len(li2):
            count_item(data, li2[i])
        if i < len(li3):
            count_item(data, li3[i])
    print(data)


combine_lists([1, 2, 3, 4, 5, 6, 7, 8, 9], [2, 4, 6, 8, 10], [3, 5, 7, 9, 11])
