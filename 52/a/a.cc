#include <iostream>
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
    vector<int> a(3);
    for (int i = 0; i < n; ++i) {
      int ai;
      read(ai);
      a[ai - 1]++;
    }
    int ans = n;
    for (int i = 0; i < 3; ++i)
      ans = min(ans, n - a[i]);
    cout << ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}