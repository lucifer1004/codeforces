n = int(input())
a = list(map(int, input().split(' ')))
if len(set(a)) == n:
    print(0)
else:
    first = dict()
    last = dict()
    for i in range(n):
        if not a[i] in first:
            first[a[i]] = i
        last[a[i]] = i
    r = n
    while last[a[r - 1]] == r - 1:
        r -= 1
    ans = r
    for i in range(n):
        if first[a[i]] != i:
            break
        r = max(r, i + 1, last[a[i]] + 1)
        ans = min(ans, r - i - 1)
    print(ans)
