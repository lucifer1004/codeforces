def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    a, b, c = read_ints()
    lo = min(a, b, c)
    s = sum([a, b, c])
    print('YES' if s % 9 == 0 and s // 9 <= lo else 'NO')
