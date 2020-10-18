#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll tot = 0, sum = 0;
    map<int, ll> cnt;
    int len = 0;
    ll zeros = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == '0') {
        zeros++;
        if (len > 0) {
          for (int j = 1; j <= len; ++j) {
            cnt[j]++;
            sum += j;
            tot += (ll)(len + 1 - j) * j;
          }
          len = 0;
        }
      } else {
        len++;
        vector<int> up;
        ll changed = 0;
        if (zeros)
          cnt[0] = zeros;
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
          if (it->first >= len)
            break;
          sum += (ll)(len - it->first) * it->second;
          changed += it->second;
          up.emplace_back(it->first);
        }
        for (auto i : up)
          cnt.erase(i);
        cnt[len] += changed;
        zeros = 0;
      }
      tot += sum;
    }
    if (len > 0)
      for (int j = 1; j <= len; ++j)
        tot += (ll)(len + 1 - j) * j;
    cout << tot;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}