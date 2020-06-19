def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    a, b, n = read_ints()
    times = 0
    while a <= n and b <= n:
        times += 1
        if a > b:
            b += a
        else:
            a += b
    print(times)
