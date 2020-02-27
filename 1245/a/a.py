def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)


t = int(input())
for case_num in range(t):
    a, b = map(int, input().split(' '))
    print("Finite" if gcd(a, b) == 1 else "Infinite")
