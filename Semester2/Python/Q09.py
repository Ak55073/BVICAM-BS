def compute(text):
    letter, word, lines = 0, 1, 1
    last = ""
    for i in text:
        if i == "\n":
            if last != "\n":
                lines += 1
                word += 1
                last = "\n"
        elif i == " ":
            if last != " ":
                word += 1
                last = " "
        else:
            last = "."
            letter += 1
    print("Letter: %d | Word: %d | Lines: %d" % (letter, word, lines))


compute(open("data.txt").read())
