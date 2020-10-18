#include <cstdio>
#include <iostream>
#include <queue>
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

ll calc(int len, int n) {
  if (n >= len)
    return len;
  ll l = len / n;
  ll rem = len % n;
  return l * l * (n - rem) + (l + 1) * (l + 1) * rem;
}

class Solution {
public:
  void solve() {
    int n, k;
    read(n), read(k);
    vector<int> a(n), parts(n, 1);
    vector<ll> now(n);
    priority_queue<pair<ll, int>> pq;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
      read(a[i]);
      now[i] = (ll)a[i] * a[i];
      sum += now[i];
      ll delta = now[i] - calc(a[i], 2);
      pq.emplace(delta, i);
    }
    while (k > n) {
      auto [delta, idx] = pq.top();
      pq.pop();
      sum -= delta;
      parts[idx]++;
      now[idx] -= delta;
      pq.emplace(now[idx] - calc(a[idx], parts[idx] + 1), idx);
      k--;
    }
    printf("%lld", sum);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}