def count_characters(text):
    data = dict()
    for i in text:
        if i == " ":
            continue

        if i in data.keys():
            data[i] += 1
        else:
            data[i] = 1
    print(data)


count_characters("This is some random text by Abhinav Kumar")
