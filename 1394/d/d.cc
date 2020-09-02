#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

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
  vector<int> t, h, in, out, deg;
  vector<set<int>> adj;
  vector<bool> vis;
  ll ans = 0;

  void dfs(int u, int p) {
    for (int v : adj[u]) {
      if (v == p)
        continue;
      dfs(v, u);
      if (h[u] > h[v])
        in[u]++, out[v]++;
      if (h[u] < h[v])
        out[u]++, in[v]++;
    }
    vector<int> vv(adj[u].begin(), adj[u].end());
    for (int v : vv)
      if (v != p && h[u] != h[v]) {
        adj[u].erase(v);
        adj[v].erase(u);
      }
  }

  pair<ll, ll> dfs2(int u, int p) {
    vis[u] = true;
    ll f = 0, g = 0;
    vector<ll> fc, gc;
    for (int v : adj[u]) {
      if (v == p)
        continue;
      auto [fci, gci] = dfs2(v, u);
      fc.emplace_back(fci), gc.emplace_back(gci);
    }
    int c = fc.size();
    vector<int> order(c);
    for (int i = 0; i < c; ++i)
      order[i] = i;
    sort(order.begin(), order.end(),
         [&](int i, int j) { return fc[i] - gc[i] > fc[j] - gc[j]; });
    vector<ll> sum(c + 1);
    ll gsum = 0;
    for (int i = 1; i <= c; ++i) {
      sum[i] = sum[i - 1] + fc[order[i - 1]] - gc[order[i - 1]];
      gsum += gc[order[i - 1]];
    }
    for (int i = 0; i <= c; ++i) {
      ll fcurr =
          (ll)t[u] * min(in[u] + (p != 0) + c - i, out[u] + i) + sum[i] + gsum;
      ll gcurr =
          (ll)t[u] * min(in[u] + c - i, out[u] + (p != 0) + i) + sum[i] + gsum;
      f = max(f, fcurr);
      g = max(g, gcurr);
    }
    return {f, g};
  }

public:
  void solve() {
    int n;
    read(n);
    t = vector<int>(n + 1), h = vector<int>(n + 1);
    adj = vector<set<int>>(n + 1);
    deg = vector<int>(n + 1);
    for (int i = 1; i <= n; ++i)
      read(t[i]);
    for (int i = 1; i <= n; ++i)
      read(h[i]);
    for (int i = 1; i < n; ++i) {
      int u, v;
      read(u), read(v);
      adj[u].insert(v);
      adj[v].insert(u);
      deg[u]++, deg[v]++;
    }
    in = vector<int>(n + 1);
    out = vector<int>(n + 1);
    dfs(1, 0);
    vis = vector<bool>(n + 1);
    for (int i = 1; i <= n; ++i) {
      ans += (ll)t[i] * deg[i];
      if (!vis[i])
        ans -= dfs2(i, 0).first;
    }
    printf("%lld", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}