#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> p(n), c(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &p[i]);
      p[i]--;
    }
    vector<int> vis(n);
    vector<vector<int>> cycles;
    for (int i = 0; i < n; ++i) {
      if (vis[i])
        continue;
      vector<int> seq = {i};
      int j = p[i];
      while (j != i) {
        vis[j] = true;
        seq.emplace_back(j);
        j = p[j];
      }
      cycles.emplace_back(seq);
    }
    for (int i = 0; i < n; ++i)
      scanf("%d", &c[i]);
    int ans = n;
    for (vector<int> &cycle : cycles) {
      int len = cycle.size();
      ans = min(ans, len);
      if (ans == 1)
        break;
      for (int i = 1; i <= min(len / 2, ans - 1); ++i) {
        if (len % i != 0)
          continue;
        bool found = false;
        for (int j = 0; j < i; ++j) {
          bool ok = true;
          for (int k = j + i; k < len; k += i)
            if (c[cycle[k]] != c[cycle[j]]) {
              ok = false;
              break;
            }
          if (ok) {
            found = true;
            break;
          }
        }
        if (found)
          ans = min(ans, i);
      }
    }
    printf("%d\n", ans);
  }
}