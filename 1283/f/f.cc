#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
  int max_free;
  vector<bool> visited;
  vector<int> parent;
  vector<unordered_set<int>> children;

  void dfs(int i) {
    visited[i] = true;
    for (int j : children[i]) {
      if (!visited[j]) {
        if (i != 0)
          cout << i << " " << j << endl;
        dfs(j);
      }
    }
  }

public:
  void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i < n; ++i)
      scanf("%d", &a[i]);

    children = vector<unordered_set<int>>(n + 1);
    parent = vector<int>(n + 1, -1);
    children[0].insert(n);
    parent[n] = 0;
    max_free = n;
    for (int i = 1; i < n; ++i) {
      if (parent[a[i]] == -1) {
        if (!children[a[i]].empty()) {
          max_free--;
          while (!children[max_free].empty())
            max_free--;
        }
        if (parent[max_free] != -1) {
          int p = parent[max_free];
          children[p].erase(max_free);
          children[p].insert(a[i]);
        }
      } else {
        max_free--;
        while (!children[max_free].empty())
          max_free--;
      }
      children[a[i]].insert(max_free);
      parent[max_free] = a[i];
    }

    cout << a[1] << endl;
    visited = vector<bool>(n + 1);
    dfs(0);
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}