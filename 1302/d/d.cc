#include <climits>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

struct Edge {
  int to;
  ll cost;
};

class Solution {
public:
  void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<ll> dist(n, LLONG_MAX);
    dist[0] = 0;
    vector<vector<Edge>> adj(n);
    for (int i = 0; i < m; ++i) {
      int u, v, cost;
      scanf("%d%d%d", &u, &v, &cost);
      u--, v--;
      adj[u].emplace_back(Edge{v, cost});
      adj[v].emplace_back(Edge{u, cost});
    }
    priority_queue<pair<ll, int>> pq;
    vector<bool> relaxed(n);
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
      pair<ll, int> top = pq.top();
      pq.pop();
      ll cost = top.first;
      int curr = top.second;
      if (relaxed[curr])
        continue;
      relaxed[curr] = true;
      for (auto edge : adj[curr]) {
        ll new_cost = dist[curr] + edge.cost;
        if (new_cost < dist[edge.to]) {
          dist[edge.to] = new_cost;
          pq.push(make_pair(new_cost, edge.to));
        }
      }
    }
    if (dist[n - 1] == LLONG_MAX)
      printf("-1");
    else
      printf("%lld", dist[n - 1]);
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}
