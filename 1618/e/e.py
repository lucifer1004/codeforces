from sys import stdin


def read_int():
    return int(stdin.readline())


def read_ints():
    return map(int, stdin.readline().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    b = list(read_ints())
    sb = sum(b)
    if sb % (n * (n + 1) // 2) != 0:
        print('NO')
        continue

    sa = sb // (n * (n + 1) // 2)
    if sa < n:
        print('NO')
        continue

    if any(bi < (n * (n + 1) // 2) for bi in b):
        print('NO')
        continue

    ans = [0] * n
    valid = True
    for i in range(n):
        delta = sa - (b[(i + 1) % n] - b[i])
        if delta % n != 0 or delta <= 0:
            valid = False
            break
        ans[(i + 1) % n] = delta // n

    if valid:
        print('YES')
        print(' '.join(map(str, ans)))
    else:
        print('NO')
