#include <cstdio>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }

class Solution {
 public:
  void solve() {
    int n;
    read(n);
    vector<int> a(n), right(n);
    for (int i = 0; i < n; ++i) {
      read(a[i]);
      right[i] = (i + 1) % n;
    }
    list<pair<int, int>> segs;
    int l = 0;
    for (int i = 1; i < n; ++i) {
      if (gcd(a[i - 1], a[i]) == 1) {
        segs.emplace_back(l, i - 1);
        l = i;
      }
    }
    segs.emplace_back(l, n - 1);

    vector<int> deleted;
    auto it = segs.begin();
    while (it != segs.end()) {
      auto nxt = (next(it) == segs.end()) ? segs.begin() : next(it);
      int g = gcd(a[it->second], a[nxt->first]);
      if (g == 1) {
        deleted.emplace_back(nxt->first + 1);
        right[it->second] = right[nxt->first];
        if (nxt->first == nxt->second) {
          ++nxt;
          segs.erase(prev(nxt));
          if (nxt == segs.end()) nxt = segs.begin();
        } else
          nxt->first = right[nxt->first];
      } else {
        if (it == nxt) break;
        if (it->second < nxt->first) {
          nxt->first = it->first;
          segs.erase(it);
        }
      }
      it = nxt;
    }

    printf("%lld ", deleted.size());
    for (int i : deleted) printf("%d ", i);
    printf("\n");
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