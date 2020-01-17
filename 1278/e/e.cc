#include <cstring>
#include <iostream>
#include <vector>
#define MAX 500005

using namespace std;
typedef long long ll;
int l[MAX], r[MAX];
vector<int> adj[MAX];
bool visited[MAX];

class Tree {
  int n, to_assign;

  void assign(int i) {
    if (l[i] == 0)
      l[i] = to_assign++;
    visited[i] = true;
    for (int j : adj[i]) {
      if (visited[j])
        continue;
      l[j] = to_assign++;
    }
    r[i] = to_assign++;
    int m = adj[i].size();
    for (int k = m - 1; k >= 0; --k) {
      if (visited[adj[i][k]])
        continue;
      visited[adj[i][k]] = true;
      assign(adj[i][k]);
    }
  }

public:
  Tree(int n) { this->n = n; }

  void connect(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  void solve() {
    to_assign = 1;
    assign(1);
    for (int i = 1; i <= n; ++i) {
      printf("%d %d\n", l[i], r[i]);
    }
  }
};

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    Tree tree = Tree(n);
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(visited, false, sizeof(visited));
    for (int i = 1; i < n; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      tree.connect(a, b);
    }

    tree.solve();
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}