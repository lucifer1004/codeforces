#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  vector<int> primes = {2, 3, 5, 7, 11, 13};
  for (int k = 17; k < 1200; k += 2) {
    bool is_prime = true;
    for (int j = 0; primes[j] * primes[j] <= k; ++j)
      if (k % primes[j] == 0) {
        is_prime = false;
        break;
      }
    if (is_prime)
      primes.emplace_back(k);
  }
  set<int> p;
  set<pair<int, int>> edges;
  bool rep = false;

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    vector<int> f;
    for (int j = 0; primes[j] * primes[j] <= a; ++j) {
      int cnt = 0;
      while (a % primes[j] == 0) {
        a /= primes[j];
        cnt++;
      }
      if (cnt % 2 == 1) {
        f.emplace_back(primes[j]);
        p.insert(primes[j]);
      }
    }
    if (a != 1) {
      f.emplace_back(a);
      p.insert(a);
    }
    if (f.empty()) {
      cout << 1;
      return 0;
    }
    pair<int, int> edge =
        f.size() == 1 ? make_pair(1, f[0]) : make_pair(f[0], f[1]);
    if (edges.find(edge) != edges.end())
      rep = true;
    else
      edges.insert(edge);
  }
  if (rep) {
    cout << 2;
    return 0;
  }

  p.insert(1);
  int d = p.size();
  vector<int> pv(p.begin(), p.end());
  vector<vector<int>> adj(d);
  unordered_map<int, int> dict;
  int idx = 0;
  for (int i : p)
    dict[i] = idx++;
  for (pair<int, int> edge : edges) {
    int u = dict[edge.first];
    int v = dict[edge.second];
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  int ans = -1;
  for (int i = 0; i < d && pv[i] <= 1000; ++i) {
    if (adj[i].empty())
      continue;
    vector<int> vis(d, -1), parent(d, -1);
    vis[i] = 0;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (vis[v] == -1) {
          vis[v] = vis[u] + 1;
          parent[v] = u;
          q.push(v);
        } else if (vis[v] > 0 && v != parent[u]) {
          int cycle = vis[u] + vis[v] + 1;
          if (ans == -1 || ans > cycle) {
            ans = cycle;
            break;
          }
        }
      }
    }
  }
  cout << ans;
}