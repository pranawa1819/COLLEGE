def factorial(n):
    if n == 0:
        return 1
    else:
        return n*factorial(n-1)
 
# Driver Code
num = int(input("Enter the value to find a factorial:" ))
print("Factorial of",num,"is",factorial(num))