def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


a, b, c, d = read_ints()
ans = 0
m = min(c - b, d - c)
n = max(c - b, d - c)
for delta in range(d - b + 1):
    right = 0
    if delta <= m:
        right = delta + 1
    elif delta <= n:
        right = m + 1
    else:
        right = d - b - delta + 1
    left = max(0, b - max(delta + 1, a) + 1)
    ans += left * right
print(ans)
