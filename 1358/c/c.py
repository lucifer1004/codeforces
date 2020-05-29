def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    x1, y1, x2, y2 = read_ints()
    d1 = x2 - x1
    d2 = y2 - y1
    print(d1 * d2 + 1)
