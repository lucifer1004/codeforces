def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, r = read_ints()
    r = min(r, n)
    l = min(r, n - 1)
    ans = l * (l + 1) // 2
    if r == n:
        ans += 1
    print(ans)
