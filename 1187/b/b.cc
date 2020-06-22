#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  int n, m;
  string s, t;
  cin >> n >> s >> m;
  vector<vector<int>> pos(26);
  vector<int> cnt(26);
  for (int i = 0; i < n; ++i)
    pos[s[i] - 'a'].emplace_back(i);
  for (int i = 0; i < m; ++i) {
    cin >> t;
    fill(cnt.begin(), cnt.end(), 0);
    for (char c : t)
      cnt[c - 'a']++;
    int ans = -1;
    for (int j = 0; j < 26; ++j)
      if (cnt[j])
        ans = max(ans, pos[j][cnt[j] - 1]);
    cout << ans + 1 << endl;
  }
}