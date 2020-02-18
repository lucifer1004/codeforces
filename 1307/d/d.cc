#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
  int n;
  vector<vector<int>> adj;

  vector<int> bfs(int i) {
    vector<int> dist(n + 1, -1);
    dist[i] = 0;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u])
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
    }
    return dist;
  }

public:
  Graph(int n) {
    this->n = n;
    adj = vector<vector<int>>(n + 1);
  }

  void add_edge(int u, int v) {
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  void solve(vector<int> &a) {
    vector<int> s = bfs(1), e = bfs(n);
    vector<pair<int, int>> v;
    for (int i : a)
      v.emplace_back(s[i] - e[i], i);
    sort(v.begin(), v.end());
    int smax = INT_MIN, origin = s[n], lmax = 0;
    for (pair<int, int> p : v) {
      lmax = max(lmax, smax + e[p.second] + 1);
      smax = max(smax, s[p.second]);
    }
    printf("%d", min(origin, lmax));
  }
};

class Solution {
public:
  void solve() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    Graph graph(n);
    vector<int> a(k);
    for (int i = 0; i < k; ++i)
      scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      graph.add_edge(u, v);
    }
    graph.solve(a);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}