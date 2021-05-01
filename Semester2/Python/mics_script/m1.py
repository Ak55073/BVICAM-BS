def odd_even(number):
    print("Even" if number % 2 == 0 else "Odd")


try:
    num = int(input("Enter a number: "))
    odd_even(num)
except ValueError:
    print("Only Integer value are accepted.")
