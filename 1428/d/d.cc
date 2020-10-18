#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
      read(a[i]);
    if (a[n] > 1) {
      printf("-1");
      return;
    }
    vector<pair<int, int>> pos;
    vector<int> b(n + 1), row(n + 1);
    int u = 1;
    set<int> both, only_up;
    for (int i = n; i >= 1; --i) {
      if (a[i] == 0)
        continue;
      if (a[i] == 1) {
        b[i] = u;
        pos.emplace_back(i, u);
        u++;
        both.insert(i);
      }
      if (a[i] == 2) {
        if (both.empty()) {
          printf("-1");
          return;
        }
        int r = *both.begin();
        b[i] = b[r];
        pos.emplace_back(i, b[r]);
        both.erase(r);
        only_up.insert(i);
      }
      if (a[i] == 3) {
        int r = -1;
        if (!only_up.empty())
          r = *only_up.begin();
        if (r == -1 && !both.empty())
          r = *both.begin();
        if (r == -1) {
          printf("-1");
          return;
        }
        b[i] = u;
        pos.emplace_back(i, u);
        pos.emplace_back(r, u);
        u++;
        only_up.insert(i);
        only_up.erase(r);
        both.erase(r);
      }
    }
    cout << pos.size() << endl;
    for (auto p : pos)
      cout << n + 1 - p.second << " " << p.first << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}