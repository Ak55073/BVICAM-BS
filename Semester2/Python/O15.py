def compute(text):
    check_line = int(input("Enter line to search:"))

    if check_line <= 0 or check_line > text.count("\n")+1:
        print("Line not found!")
        return

    text = text.split("\n")[check_line - 1]
    print(text)
    letter, word, lines = 0, 1, 1
    for i in text:
        if i == "\n":
            lines += 12
        elif i == " ":
            word += 1
        else:
            letter += 1

    print("Letter: %d | Word: %d | Lines: %d" % (letter, word, lines))


compute("This is some random line\nwhich you should\ntotally! ignore")
