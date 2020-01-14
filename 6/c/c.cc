#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];
    int l = -1, r = n, at = 0, bt = 0, alice = 0, bob = 0;
    while (alice + bob < n) {
      if (at <= bt) {
        at += t[++l];
        alice++;
      } else {
        bt += t[--r];
        bob++;
      }
    }
    cout << alice << " " << bob;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}