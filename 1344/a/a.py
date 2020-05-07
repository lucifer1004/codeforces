def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    s = set()
    for i in range(n):
        m = (i + a[i]) % n
        if m < 0:
            m += n
        s.add(m)
    print('YES' if len(s) == n else 'NO')
