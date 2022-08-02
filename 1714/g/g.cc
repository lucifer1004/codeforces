#include <cstdio>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;

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

const int K = 20;

class Solution {
  vector<vector<tuple<int, int, int>>> adj;
  vector<vector<ll>> bup;
  vector<vector<int>> par;
  vector<int> dep;
  vector<ll> sa, sb;

  void dfs(int u) {
    for (auto &[v, a, b] : adj[u]) {
      sa[v] = sa[u] + a;
      sb[v] = sb[u] + b;
      dep[v] = dep[u] + 1;
      bup[v][0] = b;
      par[v][0] = u;
      dfs(v);
    }
  }

public:
  void solve() {
    int n;
    read(n);
    adj = vector<vector<tuple<int, int, int>>>(n + 1);
    sa = vector<ll>(n + 1), sb = vector<ll>(n + 1);
    dep = vector<int>(n + 1);
    bup = vector<vector<ll>>(n + 1, vector<ll>(K));
    par = vector<vector<int>>(n + 1, vector<int>(K));
    for (int i = 2; i <= n; ++i) {
      int p, a, b;
      read(p), read(a), read(b);
      adj[p].emplace_back(i, a, b);
    }

    dfs(1);
    for (int k = 1; k < K; ++k) {
      for (int i = 1; i <= n; ++i) {
        par[i][k] = par[par[i][k - 1]][k - 1];
        bup[i][k] = bup[i][k - 1] + bup[par[i][k - 1]][k - 1];
      }
    }

    for (int i = 2; i <= n; ++i) {
      ll target = sb[i] - sa[i];
      ll now = 0;
      int ans = 0, p = i;
      for (int k = K - 1; k >= 0; --k) {
        if (par[p][k] == 0)
          continue;
        if (now + bup[p][k] <= target) {
          now += bup[p][k];
          p = par[p][k];
          ans |= 1 << k;
        }
      }
      if (now < target && par[p][0] != 0) {
        ans++;
      }
      printf("%d ", dep[i] - ans);
    }
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