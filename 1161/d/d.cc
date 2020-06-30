#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#define MOD 998244353

using namespace std;
typedef long long ll;

ll two[1005];

class Graph {
  int n;
  vector<unordered_map<int, int>> adj;
  vector<int> color;

public:
  Graph(int n) : n(n) {
    adj = vector<unordered_map<int, int>>(n);
    color = vector<int>(n);
  }

  void add_edge(int u, int v, int type) { adj[u][v] = adj[v][u] = type; }

  int solve() {
    int components = 0;
    for (int i = 0; i < n; ++i) {
      if (color[i])
        continue;
      color[i] = 1;
      components++;
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, t] : adj[u]) {
          if (t == 0) {
            if (!color[v]) {
              color[v] = color[u];
              q.push(v);
            } else if (color[v] != color[u])
              return 0;
          } else {
            if (!color[v]) {
              color[v] = 3 - color[u];
              q.push(v);
            } else if (color[v] == color[u])
              return 0;
          }
        }
      }
    }
    return two[components - 1];
  }
};

int main() {
  string s;
  cin >> s;
  int n = s.size();
  if (n == 1) {
    cout << 0;
    return 0;
  }
  two[0] = 1;
  for (int i = 1; i <= n; ++i)
    two[i] = (two[i - 1] << 1) % MOD;
  ll ans = 0;
  // Length of a
  for (int i = 1; i < n; ++i) {
    Graph g(n + i + 2);
    g.add_edge(0, 1, 1);
    g.add_edge(1, 2, 0);
    g.add_edge(1, n + 1, 0);
    g.add_edge(1, n + 2, 0);
    g.add_edge(1, n + i + 1, 0);
    for (int j = 1; j <= n - i; ++j) {
      if (s[j - 1] == '0')
        g.add_edge(0, j + 1, 0);
      else if (s[j - 1] == '1')
        g.add_edge(1, j + 1, 0);
    }
    for (int j = 1; j <= n / 2; ++j)
      g.add_edge(j + 1, n - j + 2, 0);
    for (int j = 1; j <= i / 2; ++j)
      g.add_edge(n + j + 1, n + i - j + 2, 0);
    for (int j = n - i + 1; j <= n; ++j) {
      if (s[j - 1] == '0')
        g.add_edge(j + 1, j + i + 1, 0);
      else if (s[j - 1] == '1')
        g.add_edge(j + 1, j + i + 1, 1);
    }
    ans = (ans + g.solve()) % MOD;
  }
  cout << ans;
}