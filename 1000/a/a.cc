#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    int n;
    cin >> n;
    unordered_map<string, int> cnt;
    string size;
    for (int i = 0; i < n; ++i) {
      cin >> size;
      cnt[size]++;
    }

    for (int i = 0; i < n; ++i) {
      cin >> size;
      cnt[size]--;
    }

    int ans = 0;
    for (auto p : cnt) {
      if (p.second < 0) ans -= p.second;
    }

    cout << ans;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}