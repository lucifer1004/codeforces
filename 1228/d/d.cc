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
        if (adj[v].size() <= B) {
          for (int w : adj[v])
            if (adj[u].find(w) != adj[u].end()) {
              a = u, b = v, c = w;
              found = true;
              break;
            }
        } else {
          for (int w : adj[u])
            if (adj[v].find(w) != adj[v].end()) {
              a = u, b = v, c = w;
              found = true;
              break;
            }
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
      vector<unordered_set<int>> v(4);
      for (int i = 1; i <= n; ++i) {
        if (i == a || i == b || i == c)
          continue;
        int num = 6;
        if (adj[i].find(a) != adj[i].end())
          num -= 1;
        if (adj[i].find(b) != adj[i].end())
          num -= 2;
        if (adj[i].find(c) != adj[i].end())
          num -= 3;
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
      if (ok) {
        for (int i : v[1])
          for (int j : v[2]) {
            if (adj[i].find(j) == adj[i].end()) {
              ok = false;
              break;
            }
            if (!ok)
              break;
          }
      }

      if (ok) {
        for (int i : v[1])
          for (int j : v[3]) {
            if (adj[i].find(j) == adj[i].end()) {
              ok = false;
              break;
            }
            if (!ok)
              break;
          }
      }

      if (ok) {
        for (int i : v[2])
          for (int j : v[3]) {
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