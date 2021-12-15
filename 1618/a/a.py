from sys import stdin


def read_int():
    return int(stdin.readline())


def read_ints():
    return map(int, stdin.readline().split(' '))


t = read_int()
for case_num in range(t):
    arr = list(read_ints())
    arr.sort()
    a = arr[0]
    c = arr[-3] - a
    b = arr[-1] - a - c
    print(' '.join(map(str, [a, b, c])))
