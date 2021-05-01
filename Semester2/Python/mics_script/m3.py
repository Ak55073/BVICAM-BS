def odd_even(num):
    number = num
    rev = 0
    while number > 0:
        a = number % 10
        rev = rev * 10 + a
        number = number // 10
    print(rev)


try:
    num = int(input("Enter a number: "))
    odd_even(num)
except ValueError:
    print("Only Integer value are accepted.")
