# factorial using tail recursion
def factorial(n, acc=1):
    if n == 0:
        return acc
    else:
        return factorial(n-1, acc*n)
    
num = input("Enter a number: ")
answer= factorial(int(num))
print(f"The factorial of {num} is {answer}")