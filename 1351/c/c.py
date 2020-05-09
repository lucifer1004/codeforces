def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    path = input()
    pos = (0, 0)
    ans = 0
    use = set()
    d = {'N': (0, 1), 'S': (0, -1), 'W': (-1, 0), 'E': (1, 0)}
    for c in path:
        ci, cj = pos
        di, dj = d[c]
        ni, nj = ci + di, cj + dj
        pos = (ni, nj)
        if ((ci, cj), (ni, nj)) in use:
            ans += 1
        else:
            ans += 5
            use.add(((ci, cj), (ni, nj)))
            use.add(((ni, nj), (ci, cj)))
    print(ans)
