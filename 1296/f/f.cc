#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct Edge {
  int u, v, val;
};

struct Query {
  int u, v, lo;
  bool operator<(const Query a) const { return lo < a.lo; }
};

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<unordered_map<int, int>> adj(n + 1);
    vector<Edge> e;
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      e.emplace_back(Edge{u, v, 1});
      adj[u][v] = i;
      adj[v][u] = i;
    }
    int m;
    scanf("%d", &m);
    vector<Query> q;
    for (int i = 0; i < m; ++i) {
      int u, v, c;
      scanf("%d%d%d", &u, &v, &c);
      q.emplace_back(Query{u, v, c});
    }
    sort(q.begin(), q.end());

    vector<vector<int>> pre(m);
    for (int i = 0; i < m; ++i) {
      pre[i] = vector<int>(n + 1);
      vector<bool> visited(n + 1);
      queue<int> bfs;
      bfs.push(q[i].u);
      visited[q[i].u] = true;
      while (!bfs.empty()) {
        int f = bfs.front();
        bfs.pop();
        if (f == q[i].v)
          break;
        for (auto j : adj[f]) {
          if (!visited[j.first]) {
            bfs.push(j.first);
            visited[j.first] = true;
            pre[i][j.first] = f;
          }
        }
      }
      int curr = q[i].v;
      while (curr != q[i].u) {
        int idx = adj[curr][pre[i][curr]];
        e[idx].val = q[i].lo;
        curr = pre[i][curr];
      }
    }

    for (int i = 0; i < m; ++i) {
      int curr = q[i].v;
      bool found = false;
      while (curr != q[i].u) {
        int idx = adj[curr][pre[i][curr]];
        if (e[idx].val == q[i].lo) {
          found = true;
          break;
        }
        curr = pre[i][curr];
      }
      if (!found) {
        printf("-1");
        return;
      }
    }

    for (int i = 0; i < n - 1; ++i)
      printf("%d ", e[i].val);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}