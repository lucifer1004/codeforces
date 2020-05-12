def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, k = read_ints()
    loops = k // (n - 1)
    if k % (n - 1) == 0:
        print(loops * n - 1)
    else:
        print(loops * n + k % (n - 1))
