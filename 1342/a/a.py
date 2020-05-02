def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    x, y = read_ints()
    if x > y:
        tmp = x
        x = y
        y = tmp
    a, b = read_ints()
    p = (x + y) * a
    q = (y - x) * a + x * b
    print(min(p, q))
