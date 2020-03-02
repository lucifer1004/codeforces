#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
FILE *fin;

class Solution {
  int n, m = 0;
  vector<int> before, after;
  vector<vector<int>> adj;

public:
  void solve() {
    fscanf(fin, "%d", &n);
    before = vector<int>(n);
    after = vector<int>(n);
    vector<int> zero_nodes, non_zero_nodes;
    adj = vector<vector<int>>(n);
    for (int i = 0; i < n; ++i) {
      fscanf(fin, "%d", &before[i]);
      m += before[i];
    }
    for (int i = 0; i < n; ++i) {
      fscanf(fin, "%d", &after[i]);
      if (after[i] > 0)
        non_zero_nodes.emplace_back(i);
    }
    vector<int> delta(n);
    for (int i = 0; i < n; ++i) {
      int d = before[i] - after[i];
      if (d < 0) {
        cout << -1 << endl;
        return;
      } else
        delta[i] = d;
    }
    vector<int> nodes(n);
    for (int i = 0; i < n; ++i)
      nodes[i] = i;
    sort(nodes.begin(), nodes.end(), [&](int i, int j) {
      return delta[i] < delta[j] || (delta[i] == delta[j] && i < j);
    });
    for (int i : nodes) {
      if (zero_nodes.size() < delta[i]) {
        cout << -1 << endl;
        return;
      }
      for (int j = 0; j < delta[i]; ++j)
        adj[zero_nodes[j]].emplace_back(i);
      if (after[i] == 0)
        zero_nodes.emplace_back(i);
    }
    for (int i : non_zero_nodes) {
      if (after[i] + 1 > non_zero_nodes.size()) {
        cout << -1 << endl;
        return;
      }
      int count = 0;
      for (int j : non_zero_nodes) {
        if (j == i)
          continue;
        adj[j].emplace_back(i);
        count++;
        if (count == after[i])
          break;
      }
    }

    cout << m << endl;
    string ans;
    for (int i = 0; i < n; ++i)
      for (auto j : adj[i])
        ans += to_string(i + 1) + " " + to_string(j + 1) + "\n";
    cout << ans;
  }
};

int main() {
  fin = fopen("topo.in", "r");
  int t;
  fscanf(fin, "%d", &t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
  fclose(fin);
}