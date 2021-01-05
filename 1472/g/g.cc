#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f

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

class Solution {
public:
  void solve() {
    int n, m;
    read(n), read(m);
    vector<vector<int>> adj(n + 1);
    vector<int> dist(n + 1, INF);
    for (int i = 0; i < m; ++i) {
      int u, v;
      read(u), read(v);
      adj[u].emplace_back(v);
    }
    dist[1] = 0;
    queue<int> q;
    q.emplace(1);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (dist[v] > dist[u] + 1) {
          dist[v] = dist[u] + 1;
          q.emplace(v);
        }
      }
    }
    vector<int> order(n);
    for (int i = 0; i < n; ++i)
      order[i] = i + 1;
    sort(order.begin(), order.end(),
         [&](int i, int j) { return dist[i] > dist[j]; });
    vector<int> ans(dist);
    for (int u : order) {
      for (int v : adj[u]) {
        if (dist[v] <= dist[u])
          ans[u] = min(ans[u], dist[v]);
        else
          ans[u] = min(ans[u], ans[v]);
      }
    }
    for (int i = 1; i <= n; ++i)
      printf("%d ", ans[i]);
    printf("\n");
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