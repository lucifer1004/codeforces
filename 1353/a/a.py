def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, m = read_ints()
    if n == 1:
        print(0)
    elif n == 2:
        print(m)
    else:
        print(m * 2)
