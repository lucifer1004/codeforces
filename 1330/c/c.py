n, m = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
ok = True
for i in range(m):
    if n - a[i] < i:
        ok = False
s = [0] * (m + 1)
for i in range(m - 1, -1, -1):
    s[i] = s[i + 1] + a[i]
if s[0] < n:
    ok = False
ans = []
left = 1
for i in range(m):
    ans.append(left)
    nxt = max(left + 1, n - s[i + 1] + 1)
    if nxt > left + a[i]:
        ok = False
        break
    left = nxt
if ok:
    print(' '.join(map(str, ans)))
else:
    print(-1)
