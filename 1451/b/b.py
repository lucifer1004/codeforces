def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, q = read_ints()
    s = input()
    for i in range(q):
        l, r = read_ints()
        if (l > 1 and s[l - 1] in s[:l - 1]) or (r < n and s[r - 1] in s[r:]):
            print('YES')
        else:
            print('NO')
