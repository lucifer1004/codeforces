def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


n, s = read_ints()
if s < n * 2:
    print('NO')
else:
    print('YES')
    ans = [2 if i > 0 else s - (n - 1) * 2 for i in range(n)]
    print(' '.join(map(str, ans)))
    print(1)
