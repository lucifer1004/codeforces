#include <cstdio>
#include <iostream>
#include <queue>
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
    int n;
    read(n);
    vector<int> a(n), b(n);
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
      read(a[i]);
      cnt[a[i]]++;
    }
    for (int i = 0; i < n; ++i) {
      read(b[i]);
      cnt[b[i]]++;
    }
    for (int i = 1; i <= n; ++i)
      if (cnt[i] != 2) {
        printf("-1\n");
        return;
      }
    vector<int> idx(n + 1), group(n + 1);
    for (int i = 1; i <= n; ++i) {
      idx[a[i - 1]] += i;
      group[a[i - 1]]++;
      idx[b[i - 1]] += i;
      group[b[i - 1]] += 2;
    }
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
      int p = idx[a[i - 1]] - i;
      int pg = group[a[i - 1]] - 1;
      if (p != i)
        adj[i].emplace_back(p, pg == 1);
      int q = idx[b[i - 1]] - i;
      int qg = group[b[i - 1]] - 2;
      if (q != i)
        adj[i].emplace_back(q, qg == 2);
    }
    vector<int> color(n + 1);
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
      if (!color[i]) {
        queue<int> q;
        q.push(i);
        vector<int> white, black;
        color[i] = 1;
        white.emplace_back(i);
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          for (auto &[v, t] : adj[u]) {
            int c = t == 1 ? 3 - color[u] : color[u];
            if (!color[v]) {
              color[v] = c;
              q.push(v);
              if (c == 1)
                white.emplace_back(v);
              else
                black.emplace_back(v);
            } else if (color[v] != c) {
              printf("-1\n");
              return;
            }
          }
        }
        if (white.size() < black.size())
          ans.insert(ans.end(), white.begin(), white.end());
        else
          ans.insert(ans.end(), black.begin(), black.end());
      }
    }
    printf("%d\n", (int)ans.size());
    for (int i : ans)
      printf("%d ", i);
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