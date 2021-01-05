def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    w, h, n = read_ints()
    tot = 1
    while w % 2 == 0:
        w >>= 1
        tot <<= 1
    while h % 2 == 0:
        h >>= 1
        tot <<= 1
    print('YES' if tot >= n else 'NO')
