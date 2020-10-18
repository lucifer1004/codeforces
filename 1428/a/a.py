def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    x1, y1, x2, y2 = read_ints()
    if x1 == x2 or y1 == y2:
        print(abs(x1 - x2) + abs(y1 - y2))
    else:
        print(abs(x1 - x2) + abs(y1 - y2) + 2)
