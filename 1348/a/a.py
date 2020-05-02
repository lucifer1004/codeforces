def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    total = 2 ** (n + 1) - 2
    left = 2 ** (n // 2) - 2 + 2 ** n
    right = total - left
    print(left - right)
