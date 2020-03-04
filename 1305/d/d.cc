#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

#define MAXD 10

using namespace std;

class Solution {
  int n;
  vector<unordered_set<int>> adj;
  vector<vector<int>> depth;
  vector<vector<vector<int>>> p;
  unordered_set<int> possible;

  void dfs(int u, int parent, int root) {
    p[root][u][0] = parent;
    for (int i = 1; i <= MAXD; ++i) {
      if (p[root][u][i - 1] != 0)
        p[root][u][i] = p[root][p[root][u][i - 1]][i - 1];
    }
    for (int v : adj[u])
      if (depth[root][v] == -1) {
        depth[root][v] = depth[root][u] + 1;
        dfs(v, u, root);
      }
  }

  int walk(int u, int delta, int root) {
    for (int i = MAXD; i >= 0; --i) {
      if (delta & (1 << i))
        u = p[root][u][i];
    }
    return u;
  }

  int lca(int u, int v, int root) {
    int du = depth[root][u], dv = depth[root][v];
    if (du < dv) {
      swap(du, dv);
      swap(u, v);
    }
    int delta = du - dv;
    u = walk(u, delta, root);
    for (int i = MAXD; i >= 0; --i) {
      if (p[root][u][i] != p[root][v][i]) {
        u = p[root][u][i];
        v = p[root][v][i];
      }
    }
    return u == v ? u : p[root][u][0];
  }

  bool check(int u, int v) {
    vector<vector<int>> ps(n + 1);
    for (int root : possible) {
      int uv = lca(u, v, root);
      ps[uv].emplace_back(root);
    }
    for (int i = 1; i <= n; ++i)
      if (ps[i].size() > 1)
        return false;
    return true;
  }

public:
  void solve() {
    cin >> n;
    adj = vector<unordered_set<int>>(n + 1);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].insert(v);
      adj[v].insert(u);
    }
    depth = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
    p = vector<vector<vector<int>>>(
        n + 1, vector<vector<int>>(n + 1, vector<int>(MAXD + 1)));
    for (int i = 1; i <= n; ++i) {
      depth[i][i] = 0;
      dfs(i, 0, i);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 1; i <= n; ++i) {
      possible.insert(i);
      pq.push(make_pair(adj[i].size(), i));
    }

    for (int i = 0; i < n / 2; i++) {
      int a = pq.top().second;
      pq.pop();
      int b = pq.top().second;
      pq.pop();
      if (n % 2 == 1 && i == n / 2 - 1) {
        int t = pq.top().second;
        if (!check(a, b)) {
          if (check(a, t))
            b = t;
          else
            a = t;
        }
      }
      cout << "? " << a << " " << b << endl;
      int c;
      cin >> c;
      vector<int> pv(possible.begin(), possible.end());
      for (int root : pv) {
        int ab = lca(a, b, root);
        if (ab != c)
          possible.erase(root);
      }
      if (possible.size() == 1) {
        cout << "! " << *possible.begin() << endl;
        return;
      }
    }
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}