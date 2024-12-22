# greatest common divisor of two numbers
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)
  
num1 = input("Enter the first number: ")
num2 = input("Enter the second number: ")
answer= gcd(int(num1), int(num2))
print(f"The gcd of {num1} and {num2} is {answer}")