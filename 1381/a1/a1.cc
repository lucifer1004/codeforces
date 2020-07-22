#include <cstdio>
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
    string a, b;
    cin >> a >> b;
    vector<int> ans;
    vector<int> flip(n + 1);
    int tot = 0;
    auto query = [&](int idx) {
      if ((tot + flip[idx]) & 1)
        return (char)(1 - (a[idx - 1] - '0') + '0');
      return a[idx - 1];
    };
    int l = 1, r = n;
    for (int i = n; i >= 1; --i) {
      if (query(r) != b[i - 1]) {
        if (query(l) != query(r)) {
          ans.emplace_back(1);
          flip[l]++;
        }
        ans.emplace_back(i);
        tot++;
        swap(l, r);
      }
      if (r < l)
        r++;
      else
        r--;
    }
    printf("%d ", (int)ans.size());
    for (int i : ans)
      printf("%d ", i);
    printf("\n");
  }
};

int main() {
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}