def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)


t = int(input())
for case_num in range(t):
    r, b, k = map(int, input().split(' '))
    if r > b:
        tmp = r
        r = b
        b = tmp
    g = gcd(r, b)
    b = b // g
    r = r // g
    n = (b - 2) // r + 1 if b % r != 0 else b // r - 1
    print("REBEL" if n >= k else "OBEY")
