#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<int> f(n + 1);
    vector<bool> s(n + 1, true), t(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> f[i];
      if (f[i] != 0)
        s[f[i]] = false;
      else
        t[i] = true;
    }

    // u: from & !to
    // v: !from & !to
    vector<int> u, v;
    for (int i = 1; i <= n; ++i) {
      if (s[i] && t[i])
        v.push_back(i);
      else if (s[i])
        u.push_back(i);
    }

    // Solve !from & !to
    if (v.size() == 1) {
      // Use u[0] to solve v, then update u[0]
      f[v[0]] = u[0];
      u[0] = v[0];
    } else {
      // Solve v internally
      int idx = 1;
      int k = v.size();
      for (int i = 0; i < k; ++i) f[v[i]] = v[(idx++) % k];
    }

    // Solve from & !to with u
    int idx = 0;
    for (int i = 1; i <= n; ++i) {
      if (f[i] == 0) f[i] = u[idx++];
    }

    for (int i = 1; i <= n; ++i) cout << f[i] << " ";
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}