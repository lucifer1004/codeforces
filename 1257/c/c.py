t = int(input())
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    last = dict()
    ans = n + 1
    for i in range(n):
        if a[i] in last:
            ans = min(ans, i - last[a[i]] + 1)
        last[a[i]] = i
    print(-1 if ans == n + 1 else ans)
