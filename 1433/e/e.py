from math import factorial

n = int(input())
n //= 2
print(factorial(2 * n) // (n * n) // 2)
