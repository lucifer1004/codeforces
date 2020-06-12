#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define MAXN 500005

using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), val(n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == 1)
      q.push(i);
  }
  vector<int> ans;
  vector<int> order(n);
  for (int i = 0; i < n; ++i)
    order[i] = i;
  sort(order.begin(), order.end(), [&](int i, int j) { return a[i] < a[j]; });
  for (int u : order) {
    vector<int> occur(a[u] + 1);
    for (int v : adj[u])
      occur[val[v]]++;
    int idx = 1;
    while (idx <= a[u] && occur[idx] > 0)
      idx++;
    if (idx == a[u]) {
      ans.emplace_back(u + 1);
      val[u] = a[u];
    } else {
      cout << -1;
      exit(0);
    }
  }
  for (int i : ans)
    cout << i << " ";
}