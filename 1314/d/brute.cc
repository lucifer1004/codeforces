#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#define INF 0x3f3f3f3f
#define MAXN 80

using namespace std;
int d[MAXN][MAXN];
set<pair<int, int>> d2[MAXN][MAXN];

class Solution {
  int n, steps, ans, step;
  vector<int> order, used;

  int min_dist() {
    int sum = 0;
    for (int i = 0; i < steps / 2; ++i) {
      int u = order[i], v = order[i + 1];
      int current = INF;
      for (const auto &it : d2[u][v])
        if (!used[it.second]) {
          current = it.first;
          break;
        }
      if (current == INF)
        return INF;
      sum += current;
    }
    return sum;
  }

  void brute() {
    if (step == steps - 2)
      ans = min(ans, min_dist());
    else
      for (int i = 0; i < n; ++i) {
        step += 2;
        order[step >> 1] = i;
        used[i]++;
        brute();
        used[i]--;
        step -= 2;
      }
  }

public:
  void solve() {
    scanf("%d%d", &n, &steps);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        scanf("%d", &d[i][j]);
      d[i][i] = INF;
    }

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
          if (k != i && k != j) {
            d2[i][j].insert(make_pair(d[i][k] + d[k][j], k));
            if (d2[i][j].size() > steps / 2)
              d2[i][j].erase(prev(d2[i][j].end()));
          }

    order = vector<int>(steps / 2 + 1);
    used = vector<int>(n);
    used[0] = 1;
    ans = INF;
    step = 0;
    brute();
    printf("%d", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}