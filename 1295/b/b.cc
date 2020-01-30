#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    ll n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    unordered_map<ll, int> cnt;
    ll balance = 0;
    for (char c : s) {
      if (c == '0')
        balance++;
      else
        balance--;
      cnt[balance]++;
    }
    if (balance == 0) {
      if (cnt.find(x) == cnt.end()) {
        if (x != 0)
          cout << 0 << endl;
        else
          cout << 1 << endl;
      } else
        cout << -1 << endl;
    } else {
      ll ans = 0;
      for (auto p : cnt) {
        ll k = p.first;
        ll delta = x - k;
        if (delta % balance == 0 && delta / balance >= 0)
          ans += p.second;
      }
      if (x == 0)
        ans++;
      cout << ans << endl;
    }
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}