#include <cmath>
#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
  vector<unordered_set<int>> adj;

public:
  void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    adj = vector<unordered_set<int>>(n + 1);
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u].insert(v);
      adj[v].insert(u);
    }
    int B = sqrt(m);
    vector<bool> vis(n + 1);
    int a, b, c;
    bool found = false;
    for (int u = 1; u <= n; ++u) {
      vis[u] = 1;
      for (int v : adj[u]) {
        int d = adj[v].size() <= B ? v : u;
        int p = u + v - d;
        for (int w : adj[d])
          if (adj[p].find(w) != adj[p].end()) {
            a = u, b = v, c = w;
            found = true;
            break;
          }
        if (found)
          break;
      }
      if (found)
        break;
    }
    if (!found)
      printf("-1");
    else {
      vector<int> ans(n + 1);
      ans[a] = 1, ans[b] = 2, ans[c] = 3;
      vector<int> count(4, 1);
      vector<int> core = {0, a, b, c};
      vector<unordered_set<int>> v(4);
      for (int i = 1; i <= n; ++i) {
        if (i == a || i == b || i == c)
          continue;
        int num = 6;
        for (int k = 1; k <= 3; ++k)
          if (adj[i].find(core[k]) != adj[i].end())
            num -= k;
        if (num >= 1 && num <= 3) {
          ans[i] = num;
          count[num]++;
          v[num].insert(i);
        } else {
          printf("-1");
          return;
        }
      }
      ll need = (ll)count[1] * count[2] + (ll)count[1] * count[3] +
                (ll)count[2] * count[3];
      bool ok = need == m;

      for (int p = 1; p <= 2; ++p)
        for (int q = p + 1; q <= 3; ++q)
          if (ok) {
            for (int i : v[p])
              for (int j : v[q]) {
                if (adj[i].find(j) == adj[i].end()) {
                  ok = false;
                  break;
                }
                if (!ok)
                  break;
              }
          }

      if (!ok)
        printf("-1");
      else
        for (int i = 1; i <= n; ++i)
          printf("%d ", ans[i]);
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}