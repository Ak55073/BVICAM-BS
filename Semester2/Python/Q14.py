def draw_pattern_number(limit):
    possible = 1
    max_characters = (limit ** 2) - 1
    for i in range(limit):
        print(" " * (int(max_characters / 2) - (i * 3)), end="")
        for j in range(possible):
            print(f" {abs((i - j)) + 1} ", end="")
        print()
        possible += 2


def draw_pattern_star(limit):
    possible = 1
    max_characters = (limit ** 2) - 1
    for i in range(limit):
        print(" " * (int(max_characters / 2) - (i * 3)), end="")
        for j in range(possible):
            print(" * ", end="")
        print()
        possible += 2

    possible -= 2
    for i in range(limit - 1, -1, -1):
        print(" " * (int(max_characters / 2) - (i * 3)), end="")
        for j in range(possible):
            print(" * ", end="")
        print()
        possible -= 2


if __name__ == '__main__':
    n = int(input("Enter pattern limit: "))
    draw_pattern_number(n)
    print()
    draw_pattern_star(n)
