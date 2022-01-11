#include <cstdio>
#include <iostream>
#include <tuple>
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

class UnionFind {
  int n;
  int _components;
  vector<int> parent, size;

 public:
  UnionFind(int n) : n(n), _components(n) {
    parent = vector<int>(n);
    size = vector<int>(n, 1);
    for (int i = 0; i < n; ++i) parent[i] = i;
  }

  int components() { return _components; }

  int find(int idx) {
    if (parent[idx] == idx) return idx;
    return parent[idx] = find(parent[idx]);
  }

  void connect(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa != fb) {
      if (size[fa] < size[fb]) swap(fa, fb);
      parent[fb] = fa;
      size[fa] += size[fb];
      _components--;
    }
  }
};

class Solution {
 public:
  void solve() {
    int n, m;
    read(n), read(m);

    vector<tuple<int, int, int>> edges;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      read(u), read(v), read(w);
      u--, v--;
      edges.emplace_back(u, v, w);
    }

    int ans = 0;
    vector<int> candidates(m);
    for (int i = 0; i < m; ++i) candidates[i] = i;

    for (int k = 30; k >= 0; --k) {
      int msk = 1 << k;
      UnionFind uf(n);

      vector<int> nxt_candidates;
      for (int i : candidates) {
        if ((get<2>(edges[i]) & msk) == 0) {
          uf.connect(get<0>(edges[i]), get<1>(edges[i]));
          nxt_candidates.push_back(i);
        }
      }

      if (uf.components() == 1)
        candidates = move(nxt_candidates);
      else
        ans |= msk;
    }

    printf("%d\n", ans);
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