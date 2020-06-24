from collections import deque
inf = int(1e6)


class Graph:
    def __init__(self, n):
        self.n = n
        self.adj = [[] for i in range(n)]
        self.loop = inf

    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def find_loop(self):
        for i in range(n):
            q = deque()
            q.append(i)
            depth = [-1] * n
            depth[i] = 0
            while len(q) > 0:
                u = q.popleft()
                for v in self.adj[u]:
                    if depth[v] >= depth[u]:
                        self.loop = min(self.loop, depth[u] + depth[v] + 1)
                    if depth[v] == -1:
                        depth[v] = depth[u] + 1
                        q.append(v)
        return -1 if self.loop == inf else self.loop


input()
a = list(filter(lambda x: x != 0, map(int, input().split(' '))))
n = len(a)
groups = [0] * 64
for num in a:
    t = '{0:b}'.format(num)
    l = len(t)
    curr = 0
    for i in range(l):
        if t[l - i - 1] == '1':
            groups[i] += 1

loop = -1
for cnt in groups:
    if cnt >= 3:
        loop = 3
        break
if loop == 3:
    print(3)
else:
    g = Graph(n)
    for i in range(n-1):
        for j in range(i + 1, n):
            if a[i] & a[j] != 0:
                g.add_edge(i, j)
    print(g.find_loop())
