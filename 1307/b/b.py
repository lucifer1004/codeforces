t = int(input())
for case_num in range(t):
    n, x = map(int, input().split(' '))
    a = list(map(int, input().split(' ')))
    b = 0
    for i in a:
        if x % i == 0:
            b = max(b, i)
    c = max(a)
    ans = 1e10 if b == 0 else x // b
    ans = min(ans, 1 + max(1, x // c))
    print(ans)
