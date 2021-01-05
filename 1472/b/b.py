def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    s = sum(a)
    one = a.count(1)
    print('YES' if (one > 0 or n % 2 == 0) and s % 2 == 0 else 'NO')
