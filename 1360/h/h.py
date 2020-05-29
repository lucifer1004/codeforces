def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, m = read_ints()
    a = []
    for i in range(n):
        a.append(int(input(), 2))
    a.sort()
    k = 2 ** m - n
    ans = (k - 1) // 2
    for ai in a:
        if ai <= ans:
            ans += 1
    binary = '{:b}'.format(ans)
    print(binary.rjust(m, '0'))
