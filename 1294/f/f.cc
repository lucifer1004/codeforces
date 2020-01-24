#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Tree {
  int n, dl, di;
  vector<vector<int>> adj;
  vector<int> pre;
  vector<int> diameter;
  vector<bool> visited;
  queue<pair<int, int>> q;

public:
  Tree(int n) {
    this->n = n;
    adj = vector<vector<int>>(n + 1);
  }

  void add_edge(int a, int b) {
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  void bfs(bool save_pre) {
    while (!q.empty()) {
      pair<int, int> f = q.front();
      q.pop();
      if (f.second >= dl) {
        dl = f.second;
        di = f.first;
      }
      for (int i : adj[f.first]) {
        if (!visited[i]) {
          visited[i] = true;
          q.push(make_pair(i, f.second + 1));
          if (save_pre)
            pre[i] = f.first;
        }
      }
    }
  }

  void solve() {
    visited = vector<bool>(n + 1);
    visited[1] = true;
    q.push(make_pair(1, 0));
    dl = 0, di = 0;
    bfs(false);

    int ds = di;
    visited = vector<bool>(n + 1);
    visited[ds] = true;
    pre = vector<int>(n + 1);
    q.push(make_pair(ds, 0));
    dl = 0, di = 0;
    bfs(true);

    int de = di, ans = dl;
    visited = vector<bool>(n + 1);
    while (di != 0) {
      visited[di] = true;
      q.push(make_pair(di, 0));
      di = pre[di];
    }
    dl = 0, di = 0;
    bfs(false);
    ans += dl;
    if (di == 0 || di == ds || di == de)
      di = 1;
    while (di == ds || di == de)
      di++;

    cout << ans << endl;
    cout << ds << " " << de << " " << di;
  }
};

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    Tree tree(n);
    for (int i = 1; i < n; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      tree.add_edge(a, b);
    }
    tree.solve();
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}