def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    a = []
    for i in range(n):
        a.append(input())
    ans = []
    pos = [(0, 1), (1, 0), (n - 1, n - 2), (n - 2, n - 1)]
    target = '0011'
    for i, p in enumerate(pos):
        if a[p[0]][p[1]] != target[i]:
            ans.append((p[0] + 1, p[1] + 1))
    if len(ans) <= 2:
        print(len(ans))
        for r, c in ans:
            print(r, c)
    else:
        target = '1100'
        ans = []
        for i, p in enumerate(pos):
            if a[p[0]][p[1]] != target[i]:
                ans.append((p[0] + 1, p[1] + 1))
        print(len(ans))
        for r, c in ans:
            print(r, c)
