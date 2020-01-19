#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  static void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n + 2), b(n + 1), c(n + 1), last(n + 1);

    for (int i = 1; i <= n; ++i) {
      cin >> a[i] >> b[i] >> c[i];
      last[i] = i;
    }

    for (int i = 1; i <= m; ++i) {
      int u, v;
      cin >> u >> v;
      last[v] = max(last[v], u);
    }

    vector<vector<int>> end_at(n + 1);
    for (int i = 1; i <= n; ++i) {
      end_at[last[i]].push_back(i);
    }

    vector<int> surplus(n + 1);

    // If cannot pass while defending none
    // No solution!
    int warriors = k;
    for (int i = 1; i <= n; ++i) {
      if (warriors < a[i]) {
        cout << -1;
        return;
      }
      warriors += b[i];
      surplus[i] = warriors - a[i + 1];
    }

    for (int i = n - 1; i >= 1; --i) {
      surplus[i] = min(surplus[i], surplus[i + 1]);
    }

    priority_queue<int, vector<int>, greater<>> current;
    for (int i = 1; i <= n; ++i) {
      if (surplus[i] == 0)
        continue;
      for (int j : end_at[i]) {
        current.push(c[j]);
        if (current.size() > surplus[i])
          current.pop();
      }
    }

    int ans = 0;
    while (!current.empty()) {
      ans += current.top();
      current.pop();
    }
    cout << ans;
  }
};

int main() { Solution::solve(); }