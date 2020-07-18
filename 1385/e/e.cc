#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

struct Edge {
  int u, v, type;
};

class Solution {
  vector<Edge> edges;
  vector<vector<int>> adj;

public:
  void solve() {
    int n, m;
    read(n), read(m);
    adj = vector<vector<int>>(n + 1);
    vector<int> in(n + 1);
    for (int i = 0; i < m; ++i) {
      int t, x, y;
      read(t), read(x), read(y);
      int idx = edges.size();
      edges.push_back(Edge{x, y, t});
      adj[x].emplace_back(idx);
      if (t == 1)
        in[y]++;
      if (t == 0)
        adj[y].emplace_back(idx);
    }
    queue<int> q;
    int root = -1;
    for (int i = 1; i <= n; ++i) {
      if (in[i] == 0) {
        root = i;
        q.push(i);
      }
    }
    if (root == -1)
      printf("NO\n");
    else {
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i : adj[u]) {
          Edge &e = edges[i];
          if (e.type == 0 && e.u != u)
            swap(e.u, e.v);
          if (e.type == 1) {
            in[e.v]--;
            if (in[e.v] == 0)
              q.push(e.v);
          }
          e.type = 2;
        }
      }
      for (int i = 1; i <= n; ++i)
        if (in[i] != 0) {
          printf("NO\n");
          return;
        }
      printf("YES\n");
      for (Edge e : edges)
        printf("%d %d\n", e.u, e.v);
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}
