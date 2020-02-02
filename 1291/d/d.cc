#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
  int n;
  vector<vector<int>> arr;

public:
  void solve() {
    string s;
    cin >> s;
    n = s.size();
    arr = vector<vector<int>>(26, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 26; ++j) {
        arr[j][i] = arr[j][i - 1];
        if (s[i - 1] - 'a' == j)
          arr[j][i]++;
      }
    }
    int q;
    scanf("%d", &q);
    int l, r;
    for (int i = 0; i < q; ++i) {
      scanf("%d%d", &l, &r);
      if (l == r || s[l - 1] != s[r - 1])
        cout << "Yes" << endl;
      else {
        int distinct = 0;
        for (int j = 0; j < 26; ++j) {
          int num = arr[j][r] - arr[j][l - 1];
          distinct += num > 0;
        }
        if (distinct >= 3)
          cout << "Yes" << endl;
        else
          cout << "No" << endl;
      }
    }
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}