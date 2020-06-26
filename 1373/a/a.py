def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    a, b, c = read_ints()
    x = 1 if a < c else -1
    y = b if c < a * b else -1
    print(x, y)
