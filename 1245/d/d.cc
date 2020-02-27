#include <cstdio>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;
typedef long long ll;

struct Edge {
  int from = -1, to = -1;
  ll cost = INF;
};

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<int> x(n + 1), y(n + 1), c(n + 1), k(n + 1);
    for (int i = 1; i <= n; ++i)
      scanf("%d%d", &x[i], &y[i]);
    for (int i = 1; i <= n; ++i)
      scanf("%d", &c[i]);
    for (int i = 1; i <= n; ++i)
      scanf("%d", &k[i]);
    ll cost = 0;
    vector<Edge> min_edge(n + 1), chosen;
    vector<bool> selected(n + 1);
    min_edge[0].cost = 0;
    for (int i = 0; i <= n; ++i) {
      int v = -1;
      for (int j = 0; j <= n; ++j)
        if (!selected[j] && (v == -1 || min_edge[j].cost < min_edge[v].cost))
          v = j;
      selected[v] = true;
      cost += min_edge[v].cost;
      if (min_edge[v].to != -1)
        chosen.emplace_back(min_edge[v]);

      for (int to = 1; to <= n; ++to) {
        ll new_cost;
        new_cost = v == 0 ? c[to]
                          : (ll)(abs(x[v] - x[to]) + abs(y[v] - y[to])) *
                                (k[v] + k[to]);
        if (new_cost < min_edge[to].cost)
          min_edge[to] = Edge{to, v, new_cost};
      }
    }
    vector<int> direct;
    for (auto edge : chosen) {
      if (edge.from == 0)
        direct.emplace_back(edge.to);
      else if (edge.to == 0)
        direct.emplace_back(edge.from);
    }
    printf("%lld\n", cost);
    printf("%lu\n", direct.size());
    for (int i : direct)
      printf("%d ", i);
    printf("\n%lu\n", chosen.size() - direct.size());
    for (auto edge : chosen)
      if (edge.to != 0)
        printf("%d %d\n", edge.from, edge.to);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}