#include <iostream>
#include <vector>
#define MAXM 30

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> cnt(MAXM, vector<int>(n + 1));
    vector<vector<int>> pos(MAXM);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      pos[a[i]].emplace_back(i);
      for (int j = 1; j < MAXM; ++j)
        cnt[j][i + 1] = cnt[j][i] + (a[i] == j);
    }
    int ans = 0;
    for (int i = 1; i < MAXM; ++i)
      ans = max(ans, cnt[i][n]);
    for (int i = 1; i < MAXM; ++i) {
      if (pos[i].size() < 2)
        continue;
      for (int l = 0, r = pos[i].size() - 1; l < r; ++l, --r) {
        int lo = pos[i][l], hi = pos[i][r];
        int mid = 0;
        for (int j = 1; j < MAXM; ++j)
          if (j == i)
            continue;
          else
            mid = max(mid, cnt[j][hi] - cnt[j][lo]);
        ans = max(ans, (l + 1) * 2 + mid);
      }
    }
    cout << ans << endl;
  }
}