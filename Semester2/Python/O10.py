def compute_set(data):
    sum = 0
    frequency = dict()
    max_item = 0
    max_count = 0
    for i in data:
        sum += i
        frequency[i] = (frequency[i]+1) if (i in frequency.keys()) else 0
        if frequency[i] > max_count:
            max_count = frequency[i]
            max_item = i

    print("Mean is", sum / len(data))
    if len(data) % 2 == 0:
        print("Median is", (data[int(len(data) / 2)] + data[int(len(data) / 2) + 1]) / 2)
    else:
        print("Median is", data[int(len(data) / 2)])
    print("Mode is %d with frequency %d" % (max_item, max_count))


compute_set((1, 2, 7, 7, 4, 5, 6, 7, 7))
