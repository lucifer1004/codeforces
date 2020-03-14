class Graph:
    def __init__(self, n, m):
        self.nodes = n
        self.edges = m
        self.adj = [[] for i in range(n)]
        self.color = [1 for i in range(m)]
        self.vis = [0 for i in range(n)]
        self.colors = 1

    def add_edge(self, u, v, i):
        self.adj[u].append((i, v))

    def dfs(self, u):
        self.vis[u] = 1
        for i, v in self.adj[u]:
            if self.vis[v] == 1:
                self.colors = 2
                self.color[i] = 2
            if self.vis[v] == 0:
                self.dfs(v)
        self.vis[u] = 2

    def solve(self):
        for i in range(self.nodes):
            if self.vis[i] == 0:
                self.dfs(i)
        print(self.colors)
        print(' '.join(map(str, self.color)))


n, m = map(int, input().split(' '))
graph = Graph(n, m)
for i in range(m):
    u, v = map(int, input().split(' '))
    graph.add_edge(u-1, v-1, i)
graph.solve()
