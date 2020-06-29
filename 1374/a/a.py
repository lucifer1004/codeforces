def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    x, y, n = read_ints()
    ans = n // x * x + y
    if ans > n:
        ans -= x
    print(ans)
