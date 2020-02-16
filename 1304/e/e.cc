#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define INF 1e8
#define MAX 100005

using namespace std;

int depth[MAX], enter[MAX], euler[MAX * 2];
vector<int> adj[MAX], st[21];

class Tree {
  int n, root, step;

  void dfs(int i) {
    enter[i] = step;
    euler[step++] = i;
    for (int j : adj[i]) {
      if (enter[j] == -1) {
        depth[j] = depth[i] + 1;
        dfs(j);
        euler[step++] = i;
      }
    }
  }

  void calculate_sparse_table() {
    int upper = 2 * n - 1;
    int max_level = log2(upper) + 1;
    for (int level = 0; level < max_level; ++level)
      for (int i = 0; i < upper; ++i) {
        if (level == 0)
          st[level].emplace_back(euler[i]);
        else {
          st[level].emplace_back(st[level - 1][i]);
          int right = i + (1 << (level - 1));
          if (right < upper &&
              depth[st[level - 1][right]] < depth[st[level][i]])
            st[level][i] = st[level - 1][right];
        }
      }
  }

public:
  Tree(int n, int root) {
    this->n = n;
    this->root = root;
    depth[0] = INF;
  }

  void add_edge(int u, int v) {
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  void init() {
    step = 0;
    dfs(root);
    calculate_sparse_table();
  }

  int query_lca(int u, int v) {
    if (u == v)
      return u;
    int l = min(enter[u], enter[v]);
    int r = max(enter[u], enter[v]);
    int k = log2(r - l);
    int lans = st[k][l];
    int rans = st[k][r - (1 << k) + 1];
    if (depth[lans] < depth[rans])
      return lans;
    else
      return rans;
  }

  int dist(int u, int v) {
    int p = query_lca(u, v);
    return depth[u] + depth[v] - depth[p] * 2;
  }

  // Find the intersection point of node a and circle x-y
  int intersect(int a, int x, int y) {
    int z = query_lca(x, y);
    int pax = query_lca(a, x);
    int pay = query_lca(a, y);
    int pa = depth[pax] >= depth[pay] ? pax : pay;
    if (depth[pa] < depth[z])
      pa = z;
    return pa;
  }
};

bool check(int k, int b) { return k >= b && (k - b) % 2 == 0; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(depth, 0, sizeof(depth));
  memset(enter, -1, sizeof(enter));
  memset(euler, 0, sizeof(euler));

  int n;
  scanf("%d", &n);
  Tree tree = Tree(n, 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    tree.add_edge(u, v);
  }

  tree.init();

  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int x, y, a, b, k;
    scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);
    int circle = tree.dist(x, y) + 1;
    int ab = tree.dist(a, b);
    bool can = check(k, ab);

    int pa = tree.intersect(a, x, y);
    int pb = tree.intersect(b, x, y);
    int ab2 = tree.dist(a, pa) + tree.dist(b, pb) + circle - tree.dist(pa, pb);
    can = can || check(k, ab2);

    if (can)
      printf("YES\n");
    else
      printf("NO\n");
  }
}