#include <iostream>
#include <set>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    set<char> s;
    for (int i = 0; i < k; ++i) {
      char c;
      cin >> c;
      s.insert(c);
    }
    str += "$";
    ll ans = 0, count = 0;
    for (char c : str) {
      if (s.find(c) != s.end()) {
        count++;
      } else {
        ans += count * (count + 1) / 2;
        count = 0;
      }
    }
    cout << ans;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}