#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<set<int>> adj(26);
    set<char> distinct(s.begin(), s.end());
    for (int i = 0; i < n - 1; ++i) {
      int l = s[i] - 'a', r = s[i + 1] - 'a';
      if (l != r) {
        adj[l].insert(r);
        adj[r].insert(l);
      }
    }
    int edges = 0;
    for (int i = 0; i < 26; ++i) {
      if (adj[i].size() > 2) {
        cout << "NO" << endl;
        return;
      }
      edges += adj[i].size();
    }
    edges /= 2;
    if (edges + 1 != distinct.size()) {
      cout << "NO" << endl;
      return;
    }
    if (distinct.size() == 1) {
      cout << "YES" << endl;
      string ans;
      for (int i = 0; i < 26; ++i)
        ans.push_back(i + 'a');
      cout << ans << endl;
      return;
    }
    int root = 0;
    while (root < 26 && adj[root].size() != 1)
      root++;
    string ans;
    queue<int> q;
    q.push(root);
    vector<bool> vis(26);
    vis[root] = true;
    while (!q.empty()) {
      int u = q.front();
      ans.push_back(u + 'a');
      q.pop();
      for (int v : adj[u]) {
        if (!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
    }
    for (int i = 0; i < 26; ++i)
      if (!vis[i])
        ans.push_back(i + 'a');
    cout << "YES" << endl;
    cout << ans << endl;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}