#include <algorithm>
#include <cstdio>
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
    int n, d, m;
    read(n), read(d), read(m);
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
      read(a[i]);
    sort(a.begin(), a.end());
    ll ans = 0;
    vector<ll> s(n + 1);
    for (int i = 1; i <= n; ++i)
      s[i] = s[i - 1] + a[i - 1];
    int idx = 0;
    while (idx < n && a[idx] <= m)
      idx++;
    if (idx == n) {
      printf("%lld", s[n]);
      return;
    }
    for (int i = n - 1; i >= idx; --i) {
      int need = (n - i - 1) * d;
      if (need > i)
        break;
      need -= i - idx;
      if (need < 0)
        need = 0;
      ll result = s[n] - s[i];
      if (need < idx)
        result += s[idx] - s[need];
      ans = max(ans, result);
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