def compute(text):
    letter, word, lines = 0, 1, 1
    last_character = ""
    for i in text:
        if i == "\n":
            if last_character != "\n":
                lines += 1
                word += 1
                last_character = "\n"
        elif i == " ":
            if last_character != " ":
                word += 1
                last_character = " "
        else:
            last_character = i
            letter += 1
    print("Letter: %d | Word: %d | Lines: %d" % (letter, word, lines))


if __name__ == "__main__":
    file_data = open("data.txt").read()
    compute(file_data)
