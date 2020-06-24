def read_ints():
    return map(int, input().split(' '))


n, k = read_ints()
a = list(read_ints())
a.sort()
idx = n // 2
length = 1
ans = a[idx]
while idx < n - 1 and k >= length:
    nxt = a[idx + 1]
    delta = min(nxt - a[idx], k // length)
    k -= delta * length
    ans = a[idx] + delta
    idx += 1
    length += 1
if idx == n - 1 and k >= length:
    ans = a[idx] + k // length
print(ans)
