#include <cstdio>
#include <iostream>
#include <map>
#define INF 0x3f3f3f3f

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
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      int a;
      read(a);
      cnt[k - a % k]++;
    }
    int mr = 0, mx = 0, tot = 0;
    for (auto p : cnt) {
      if (p.first == k)
        continue;
      if (p.second > mr || (p.second == mr && p.first > mx)) {
        mr = p.second;
        mx = p.first;
      }
    }
    printf("%lld\n", mr == 0 ? 0 : (ll)(mr - 1) * k + mx + 1);
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