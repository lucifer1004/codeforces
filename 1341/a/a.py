def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, a, b, c, d = read_ints()
    print('Yes' if n * (a + b) >= c - d and n * (a - b) <= c + d else 'No')
