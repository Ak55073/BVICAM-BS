def remove_space(text, pos=0):
    if len(text) - 1 <= pos:
        return text
    if text[pos] == " ":
        return remove_space(text[:pos] + text[pos + 1:], pos)
    else:
        return remove_space(text, pos + 1)


if __name__ == "__main__":
    data = " Abhinav    A  b   b h   d"
    print(remove_space(data))
