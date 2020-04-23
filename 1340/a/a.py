def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    d = dict()
    for i in range(n):
        d[a[i]] = i
    ok = True
    num = 1
    pos = d[num]
    left = n - 1
    used = [False for i in range(n)]
    used[pos] = True
    while num < n:
        num += 1
        pos += 1
        if pos >= n or used[pos]:
            pos = d[num]
        if a[pos] != num:
            ok = False
            break
        used[pos] = True
    print('Yes' if ok else 'No')
