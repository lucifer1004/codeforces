#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
  void dfs(map<int, vector<int>> &adj, vector<bool> &visited, int i) {
    visited[i] = true;
    for (int j : adj[i]) {
      if (!visited[j]) dfs(adj, visited, j);
    }
  }

 public:
  void solve() {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "YES";
      return;
    }
    int num = 2 * n;
    vector<int> start(num + 1), end(num + 1);
    for (int i = 0; i < n; ++i) {
      int l, r;
      scanf("%d%d", &l, &r);
      start[l] = r;
      end[r] = l;
    }
    set<int> s;
    vector<pair<int, int>> edges;
    for (int i = 1; i <= num; ++i) {
      if (start[i] != 0) {
        for (auto it = s.begin(); it != s.end(); ++it) {
          if (*it > start[i]) break;
          edges.push_back(make_pair(i, end[*it]));
          if (edges.size() >= n) {
            cout << "NO";
            return;
          }
        }
        s.insert(start[i]);
      } else {
        s.erase(i);
      }
    }
    if (edges.size() != n - 1) {
      cout << "NO";
      return;
    }

    vector<bool> visited(num + 1);
    map<int, vector<int>> adj;
    for (auto p : edges) {
      adj[p.first].push_back(p.second);
      adj[p.second].push_back(p.first);
    }
    dfs(adj, visited, edges[0].first);
    int visit_count = count(visited.begin(), visited.end(), true);
    cout << (visit_count == n ? "YES" : "NO");
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}