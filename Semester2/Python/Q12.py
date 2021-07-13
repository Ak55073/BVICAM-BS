from math import pi


class Circle:
    def __init__(self, radius):
        self.radius = radius

    def get_area(self):
        return pi * (self.radius ** 2)

    def get_perimeter(self):
        return 2 * pi * self.radius


if __name__ == '__main__':
    circle = Circle(15)
    print(circle.get_area())
    print(circle.get_perimeter())
