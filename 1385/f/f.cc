#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

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
    int n, k;
    read(n), read(k);
    vector<set<int>> adj(n + 1), leaves(n + 1);
    vector<int> degree(n + 1);
    vector<bool> deleted(n + 1);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      read(u), read(v);
      adj[u].insert(v);
      adj[v].insert(u);
      degree[u]++, degree[v]++;
    }
    for (int i = 1; i <= n; ++i)
      if (degree[i] == 1)
        leaves[*adj[i].begin()].insert(i);
    set<pair<int, int>> pq;
    for (int i = 1; i <= n; ++i)
      if (leaves[i].size() >= k)
        pq.insert({(int)leaves[i].size() % k, i});
    int ans = 0;
    while (!pq.empty()) {
      int u = pq.begin()->second;
      int rest = leaves[u].size();
      pq.erase(pq.begin());
      if (deleted[u])
        continue;
      ans += rest / k;
      for (int i = 0; i < rest / k * k; ++i) {
        deleted[*leaves[u].begin()] = true;
        adj[u].erase(*leaves[u].begin());
        leaves[u].erase(leaves[u].begin());
        degree[u]--;
      }
      rest %= k;
      if (degree[u] == 1) {
        int v = *adj[u].begin();
        int sz = leaves[v].size();
        pq.erase({sz % k, v});
        leaves[v].insert(u);
        if (sz + 1 >= k)
          pq.insert({(sz + 1) % k, v});
      }
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