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
  int n, ans;
  string s;
  vector<vector<int>> adj;

  pair<int, int> dfs(int u) {
    int b = s[u] == 'B', w = s[u] == 'W';
    for (int v : adj[u]) {
      auto [bi, wi] = dfs(v);
      b += bi;
      w += wi;
    }

    if (b == w) ans++;

    return {b, w};
  }

 public:
  void solve() {
    read(n);
    adj = vector<vector<int>>(n);
    for (int i = 1; i < n; ++i) {
      int p;
      read(p);
      p--;
      adj[p].push_back(i);
    }
    cin >> s;

    ans = 0;
    dfs(0);
    printf("%d\n", ans);
  }
};

int main() {
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}