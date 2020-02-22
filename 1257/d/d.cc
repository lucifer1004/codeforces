#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    set<int> ps;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      ps.insert(a[i]);
    }
    int m;
    scanf("%d", &m);
    vector<int> p(m), s(m);
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &p[i], &s[i]);
      ps.insert(p[i]);
    }
    unordered_map<int, int> pd;
    int idx = 0;
    for (int i : ps)
      pd[i] = idx++;
    int d = ps.size();
    vector<int> best(d);
    for (int i = 0; i < m; ++i)
      best[pd[p[i]]] = max(best[pd[p[i]]], s[i]);
    for (int i = d - 2; i >= 0; --i)
      best[i] = max(best[i], best[i + 1]);
    int day = 1, hi = -1, cont = 0;
    for (int i = 0; i < n; ++i) {
      hi = max(hi, pd[a[i]]);
      cont++;
      if (best[hi] == 0) {
        printf("-1\n");
        return;
      }
      if (best[hi] < cont) {
        day++;
        hi = pd[a[i]];
        cont = 1;
      }
    }
    printf("%d\n", day);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  scanf("%d", &t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}