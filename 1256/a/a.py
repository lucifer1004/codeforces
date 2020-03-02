t = int(input())
for case_num in range(t):
    a, b, n, s = map(int, input().split(' '))
    if b > n:
        a += (b - n) // n
        b = b % n + n
    na = s // n
    nb = s % n
    print("YES" if (a >= na and b >= nb) or (
        a == na - 1 and b >= nb + n) else "NO")
