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
    int n;
    read(n);
    vector<ll> t(n + 1), x(n + 1);
    for (int i = 0; i < n; ++i)
      read(t[i]), read(x[i]);
    t[n] = 1LL << 60;
    ll start = 0, end = 0, start_t = 0, stop_t = 0;
    int ans = 0, direction = 1;
    for (int i = 0; i < n; ++i) {
      if (t[i] >= stop_t) {
        start_t = t[i];
        start = end;
        end = x[i];
        stop_t = abs(end - start) + t[i];
        if (stop_t <= t[i + 1])
          ans++;
        direction = end >= start ? 1 : -1;
      } else {
        ll left_span = t[i] - start_t;
        ll left = start + left_span * direction;
        ll right_span = min(stop_t - start_t, t[i + 1] - start_t);
        ll right = start + right_span * direction;
        if (min(left, right) <= x[i] && x[i] <= max(left, right))
          ans++;
      }
    }
    printf("%d\n", ans);
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