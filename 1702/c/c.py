from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    input()
    n, k = read_ints()
    u = list(read_ints())
    last = dict()
    for i, ui in enumerate(u):
        last[ui] = i
    ans = ['NO'] * k
    queries = [list(read_ints()) for _ in range(k)]
    order = list(range(k))
    order.sort(key=lambda x: last[queries[x][1]]
               if queries[x][1] in last else -1)
    ptr = 0
    vis = set()
    for i in order:
        if queries[i][1] not in last:
            continue
        while ptr <= last[queries[i][1]]:
            vis.add(u[ptr])
            ptr += 1
        if queries[i][0] in vis:
            ans[i] = 'YES'
    print('\n'.join(ans))
