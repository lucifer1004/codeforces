def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


def split_three(n):
    if n % 2 == 1:
        return [1, n // 2, n // 2]
    elif n % 4 == 2:
        return [2, n // 2 - 1, n // 2 - 1]
    else:
        return [n // 4, n // 4, n // 2]


t = read_int()
for case_num in range(t):
    n, k = read_ints()
    ans = [1] * (k - 3) + split_three(n - (k - 3))
    print(' '.join(map(str, ans)))
