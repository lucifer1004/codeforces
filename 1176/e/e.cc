#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
  vector<vector<int>> adj;
  vector<int> depth;

 public:
  Graph(int n) {
    adj = vector<vector<int>>(n);
    depth = vector<int>(n);
  }

  void connect(int a, int b) {
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  void solve() {
    int n = adj.size();

    queue<int> bfs;
    bfs.push(0);
    depth[0] = 1;
    while (!bfs.empty()) {
      int front = bfs.front();
      bfs.pop();
      for (const int &i : adj[front]) {
        if (!depth[i]) {
          depth[i] = depth[front] + 1;
          bfs.push(i);
        }
      }
    }

    int odd = 0;
    for (const int &d : depth) odd += d % 2;
    int even = n - odd;
    if (even <= odd) {
      cout << even << endl;
      for (int i = 0; i < n; ++i)
        if (depth[i] % 2 == 0) cout << i + 1 << " ";
    } else {
      cout << odd << endl;
      for (int i = 0; i < n; ++i)
        if (depth[i] % 2 != 0) cout << i + 1 << " ";
    }
    cout << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  int t;
  scanf("%d", &t);
  for (int tt = 0; tt < t; ++tt) {
    int n, m;
    scanf("%d%d", &n, &m);
    Graph g = Graph(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      g.connect(a - 1, b - 1);
    }
    g.solve();
  }
  return 0;
}