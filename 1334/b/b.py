t = int(input())
for case_num in range(t):
    n, x = map(int, input().split(' '))
    a = list(map(int, input().split(' ')))
    a.sort()
    a.reverse()
    s = 0
    ans = 0
    for i in range(n):
        s += a[i]
        if s / (i + 1) >= x:
            ans = i + 1
    print(ans)
