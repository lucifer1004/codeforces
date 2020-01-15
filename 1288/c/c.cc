#include <iostream>

using namespace std;
typedef long long ll;
const ll modulo = 1e9 + 7;
#define MAX 1003
#define LEN 13

class Solution {
 public:
  void solve() {
    int n, m;
    cin >> n >> m;

    ll f[MAX][LEN]{}, s[MAX][LEN]{};
    for (int b = 1; b <= n; ++b) {
      f[b][1] = b;
      s[b][1] = s[b - 1][1] + f[b][1];
    }
    for (int k = 2; k <= m; ++k)
      for (int b = 1; b <= n; ++b)
        for (int a = 1; a <= b; ++a) {
          f[b][k] = (f[b][k] + s[b - a + 1][k - 1]) % modulo;
          s[b][k] = (s[b - 1][k] + f[b][k]) % modulo;
        }

    cout << s[n][m];
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}