class StringManage:
    def __init__(self):
        self.text = ""

    def set_string(self):
        self.text = input("Enter a string: ")

    def get_string(self):
        return self.text.upper()


if __name__ == '__main__':
    manager = StringManage()
    manager.set_string()
    print(manager.get_string())
