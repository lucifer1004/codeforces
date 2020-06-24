def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


n = read_int()
a = list(read_ints())
a.sort()
ans = a[:2]
for i in range(2, n):
    d = int(2e9)
    idx = -1
    for j in range(i):
        curr = max(abs(ans[(j - 1 + i) % i] - a[i]), abs(ans[j] - a[i]))
        if curr < d:
            d = curr
            idx = j
    ans = ans[:idx] + [a[i]] + ans[idx:]
print(' '.join(map(str, ans)))
