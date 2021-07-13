def check_parenthesis(text: str) -> bool:
    opened_parenthesis = 0
    for i in text:
        if i == "(":
            opened_parenthesis += 1
            continue
        if i == ")":
            opened_parenthesis -= 1
    return opened_parenthesis == 0


if __name__ == "__main__":
    string = input("Enter a string: ")
    print("Given string is balanced?", check_parenthesis(string))
