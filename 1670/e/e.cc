#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

class Solution {
  int n, p1, p2;
  vector<vector<int>> adj;
  vector<int> val;

  void dfs(int u, int p, int d) {
    for (int v : adj[u]) {
      if (v == p) continue;
      if (v > n) {
        if (d % 4 == 1)
          val[v] = v;
        else
          val[v] = v ^ n;
      } else {
        val[v] = val[u] ^ n;
      }
      dfs(v, u, d + 1);
    }
  }

 public:
  void solve() {
    int p;
    read(p);
    n = 1 << p;
    adj = vector<vector<int>>(2 * n);
    val = vector<int>(2 * n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      read(u), read(v);
      int e = n + i + 1;
      adj[u].push_back(e);
      adj[e].push_back(u);
      adj[v].push_back(e);
      adj[e].push_back(v);
    }

    val[1] = 1 << p;
    p1 = 1, p2 = n + 1;
    dfs(1, 0, 1);
    printf("1\n");
    for (int i = 1; i <= n; ++i) printf("%d ", val[i]);
    printf("\n");
    for (int i = n + 1; i < n * 2; ++i) printf("%d ", val[i]);
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