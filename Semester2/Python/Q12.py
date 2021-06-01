class StringReverse:
    text = ""

    def set_string(self):
        self.text = input("Enter a string: ")

    def reverse_string(self):
        temp = self.text.split(" ")
        for i in range(len(temp)-1, -1, -1):
            print(temp[i], end=" ")


if __name__ == '__main__':
    manager = StringReverse()
    manager.set_string()
    manager.reverse_string()
