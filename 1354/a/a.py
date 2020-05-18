def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    a, b, c, d = read_ints()
    if a > b and d >= c:
        print(-1)
    elif a <= b:
        print(b)
    else:
        remain = a - b
        extra = ((remain - 1) // (c - d) + 1) * c
        print(b + extra)
