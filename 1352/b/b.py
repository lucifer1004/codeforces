def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, k = read_ints()
    if n % 2 == 0 and k % 2 == 1:
        if n < 2 * k:
            print('NO')
        else:
            print('YES')
            ans = [2 if i > 0 else n - (k - 1) * 2 for i in range(k)]
            print(' '.join(map(str, ans)))
    else:
        if (n % 2 == 1 and k % 2 == 0) or n < k:
            print('NO')
        else:
            print('YES')
            ans = [1 if i > 0 else n - k + 1 for i in range(k)]
            print(' '.join(map(str, ans)))
