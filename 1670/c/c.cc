#include <cstdio>
#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;
using ll = long long;

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

class UnionFind {
  int n;
  vector<int> parent, size;

 public:
  UnionFind(int n) {
    this->n = n;
    parent = vector<int>(n);
    size = vector<int>(n, 1);
    for (int i = 0; i < n; ++i) parent[i] = i;
  }

  int find(int idx) {
    if (parent[idx] == idx) return idx;
    return parent[idx] = find(parent[idx]);
  }

  void connect(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa != fb) {
      if (size[fa] > size[fb]) {
        parent[fb] = fa;
        size[fa] += size[fb];
      } else {
        parent[fa] = fb;
        size[fb] += size[fa];
      }
    }
  }

  vector<vector<int>> components() {
    vector<int> root(n);
    int g = 0;
    for (int i = 0; i < n; ++i) {
      if (find(i) == i) root[i] = ++g;
    }
    vector<vector<int>> ans(g);
    for (int i = 0; i < n; ++i) ans[root[find(i)] - 1].push_back(i);
    return ans;
  }
};

class Solution {
 public:
  void solve() {
    int n;
    read(n);
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) read(a[i]);
    for (int i = 0; i < n; ++i) read(b[i]);
    for (int i = 0; i < n; ++i) read(c[i]);

    UnionFind uf(n);
    for (int i = 0; i < n; ++i) uf.connect(a[i] - 1, b[i] - 1);
    auto comp = uf.components();
    int m = comp.size();
    vector<int> root(n);
    int g = 0;
    for (auto &c : comp) root[uf.find(c[0])] = ++g;
    vector<bool> fixed(m + 1);
    for (int i = 0; i < n; ++i) {
      if (c[i] != 0) fixed[root[uf.find(c[i] - 1)]] = true;
    }

    ll ans = 1;
    for (auto &c : comp) {
      if (fixed[root[uf.find(c[0])]] || c.size() == 1) continue;
      ans = ans * 2 % MOD;
    }

    printf("%lld\n", ans);
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