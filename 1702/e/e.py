from collections import deque
from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    d = [list(read_ints()) for _ in range(n)]
    mem = [[] for _ in range(n + 1)]
    valid = True
    for i, (u, v) in enumerate(d):
        if u == v:
            valid = False
            break
        mem[u].append(i)
        mem[v].append(i)
        if len(mem[u]) > 2 or len(mem[v]) > 2:
            valid = False
            break

    if not valid:
        print('NO')
        continue

    vis = [False] * (n + 1)
    num = [set() for _ in range(3)]
    state = [0] * n

    for i in range(1, n + 1):
        if vis[i]:
            continue

        dq = deque()
        dq.append(i)

        while len(dq) > 0:
            u = dq.popleft()
            a, b = mem[u]
            if state[a] == state[b] == 0:
                state[a] = 1
                state[b] = 2
                num[1].add(u)
                up1 = d[a][0] + d[a][1] - u
                num[1].add(up1)
                if not vis[up1]:
                    vis[up1] = True
                    dq.append(up1)

                num[2].add(u)
                up2 = d[b][0] + d[b][1] - u
                num[2].add(up2)
                if not vis[up2]:
                    vis[up2] = True
                    dq.append(up2)
            elif state[a] + state[b] == 3:
                continue
            elif state[a] == state[b]:
                valid = False
                break
            elif state[a] > 0:
                state[b] = 3 - state[a]
                num[state[b]].add(u)
                up2 = d[b][0] + d[b][1] - u
                num[state[b]].add(up2)
                if not vis[up2]:
                    vis[up2] = True
                    dq.append(up2)
            elif state[b] > 0:
                state[a] = 3 - state[b]
                num[state[a]].add(u)
                up1 = d[a][0] + d[a][1] - u
                num[state[a]].add(up1)
                if not vis[up1]:
                    vis[up1] = True
                    dq.append(up1)

        if not valid:
            break

    print('YES' if valid else 'NO')
