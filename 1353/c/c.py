def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    x = n // 2
    ans = x * (x + 1) * (2 * x + 1) // 6
    print(ans * 8)
