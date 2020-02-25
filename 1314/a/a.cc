#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    unordered_map<int, int> lookup;
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    vector<int> b(a);
    sort(a.begin(), a.end());
    for (int i = 1; i < n; ++i)
      a[i] = max(a[i - 1] + 1, a[i]);
    int idx = 0;
    for (int i : a)
      lookup[i] = idx++;
    vector<vector<int>> start(n);
    for (int i = 0; i < n; ++i) {
      int t;
      scanf("%d", &t);
      start[lookup[b[i]]].emplace_back(t);
    }
    priority_queue<pair<int, int>> pq;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j : start[i])
        pq.push(make_pair(j, a[i]));
      pair<int, int> top = pq.top();
      pq.pop();
      ans += (ll)(a[i] - top.second) * top.first;
    }
    printf("%lld", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}