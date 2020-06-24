#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

class Solution {
public:
  void solve() {
    int n, k;
    read(n), read(k);
    vector<int> a(n), w(k);
    for (int i = 0; i < n; ++i)
      read(a[i]);
    for (int i = 0; i < k; ++i)
      read(w[i]);
    sort(a.rbegin(), a.rend());
    sort(w.begin(), w.end());
    vector<vector<int>> dist(k);
    for (int i = 0; i < k; ++i)
      dist[i].emplace_back(a[i]);
    int idx = k;
    for (int i = 0; i < k; ++i) {
      while (dist[i].size() < w[i])
        dist[i].emplace_back(a[idx++]);
    }
    ll ans = 0;
    for (int i = 0; i < k; ++i)
      ans += dist[i].front() + dist[i].back();
    cout << ans << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}