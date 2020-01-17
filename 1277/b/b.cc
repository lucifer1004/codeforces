#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
unordered_map<int, int> cnt;

class Solution {
  pair<int, int> make_odd(int a) {
    int cnt = 0;
    while (a % 2 == 0) {
      cnt++;
      a /= 2;
    }
    return make_pair(a, cnt);
  }

 public:
  void solve() {
    int n;
    cin >> n;
    cnt.clear();

    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      pair<int, int> result = make_odd(a);
      cnt[result.first] = max(cnt[result.first], result.second);
    }
    int ans = 0;
    for (auto p : cnt) {
      ans += p.second;
    }
    cout << ans << endl;
  }
};

int main() {
  int t;
  cin >> t;
  cnt.reserve(1 << 18);
  cnt.max_load_factor(0.25);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}