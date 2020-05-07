#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
typedef long long ll;

mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }

class Solution {
public:
  void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj_less(n + 1), adj_greater(n + 1);
    vector<int> in_less(n + 1), in_greater(n + 1);
    vector<int> min_less(n + 1), min_greater(n + 1);
    for (int i = 1; i <= n; ++i)
      min_less[i] = min_greater[i] = i;
    set<int> vis;
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      adj_less[u].emplace_back(v);
      adj_greater[v].emplace_back(u);
      in_less[v]++;
      in_greater[u]++;
      vis.insert(u), vis.insert(v);
    }
    auto topo_sort = [&](vector<vector<int>> &adj, vector<int> &in,
                         vector<int> &min_idx) {
      vector<int> topo;
      queue<int> q;
      for (int i = 1; i <= n; ++i)
        if (in[i] == 0)
          q.push(i);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.emplace_back(u);
        for (int v : adj[u]) {
          in[v]--;
          min_idx[v] = min(min_idx[v], min_idx[u]);
          if (in[v] == 0)
            q.push(v);
        }
      }
      return topo.size() == n;
    };
    if (!topo_sort(adj_less, in_less, min_less) ||
        !topo_sort(adj_greater, in_greater, min_greater)) {
      cout << -1;
      return;
    }
    string ans;
    int a_count = 0;
    for (int i = 1; i <= n; ++i) {
      if (min(min_less[i], min_greater[i]) >= i) {
        a_count++;
        ans.push_back('A');
      } else
        ans.push_back('E');
    }
    cout << a_count << endl << ans << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}