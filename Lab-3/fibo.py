# fibonacci using memoization
memo = {}
def fibonacci(n):
    if n in memo:
        return memo[n]
    if n == 0:
        return 0
    if n == 1:
        return 1
    else:
        memo[n] = fibonacci(n-1) + fibonacci(n-2)
        return memo[n]
    
num = input("Enter a number: ")
answer= fibonacci(int(num))
print(f"The fibonacci of {num} is {answer}")