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

const int MAX_LEVEL = 18;

class Solution {
  vector<int> depth;
  vector<vector<int>> f, adj;

  void dfs(int u, int parent) {
    depth[u] = depth[parent] + 1;
    f[u][0] = parent;
    for (int i = 1; i <= MAX_LEVEL; ++i) {
      f[u][i] = f[f[u][i - 1]][i - 1];
      if (f[u][i] == 0) break;
    }
    for (int v : adj[u])
      if (v != parent) dfs(v, u);
  }

  int la(int u, int delta) {
    for (int i = MAX_LEVEL; i >= 0; --i) {
      if (delta & (1 << i)) u = f[u][i];
    }
    return u;
  }

  int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    u = la(u, depth[u] - depth[v]);
    for (int i = MAX_LEVEL; i >= 0; --i)
      if (f[u][i] != f[v][i]) {
        u = f[u][i];
        v = f[v][i];
      }
    return u == v ? u : f[u][0];
  }

 public:
  void solve() {
    int n;
    read(n);
    depth = vector<int>(n + 1);
    f = vector<vector<int>>(n + 1, vector<int>(MAX_LEVEL + 1));
    adj = vector<vector<int>>(n + 1);

    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      read(u), read(v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs(1, 0);

    int q;
    read(q);
    while (q--) {
      int k;
      read(k);
      vector<int> p(k);
      int md = 0, mi = 0;
      for (int i = 0; i < k; ++i) {
        read(p[i]);
        if (depth[p[i]] > md) {
          md = depth[p[i]];
          mi = p[i];
        }
      }

      vector<int> rem;
      int md1 = n;  // Minimum depth in the left chain
      for (int pi : p) {
        if (lca(pi, mi) != pi)
          rem.push_back(pi);
        else if (depth[pi] < md1)
          md1 = depth[pi];
      }

      int nd = 0, ni = 0;
      for (int ri : rem) {
        if (depth[ri] > nd) {
          nd = depth[ri];
          ni = ri;
        }
      }

      bool valid = true;
      if (depth[lca(ni, mi)] > md1) valid = false;

      for (int ri : rem) {
        if (lca(ri, ni) != ri) {
          valid = false;
          break;
        }
      }

      if (valid)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}
