t = int(input())
for case_num in range(t):
    a, b = map(int, input().split(' '))
    num = b // a
    hi = b % a
    lo = 0 if num == 0 else (b - hi * (num + 1)) // num
    print(lo * num * num + hi * (num + 1) * (num + 1))
