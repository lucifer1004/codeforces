#include <iostream>
#include <vector>
#define MAXN 200005

using namespace std;

vector<int> sub[MAXN];

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> m(n);
  vector<int> cnt(k + 1);
  for (int i = 0; i < n; ++i) {
    cin >> m[i];
    cnt[m[i]]++;
  }
  vector<int> c(k + 1);
  for (int i = 1; i <= k; ++i)
    cin >> c[i];
  int idx = 0, max_idx = 0;
  for (int i = k; i >= 1; --i) {
    if (i < k && c[i] > c[i + 1])
      idx = 0;
    while (cnt[i] > 0) {
      int put = min(c[i] - (int)sub[idx].size(), cnt[i]);
      for (int j = 1; j <= put; ++j)
        sub[idx].emplace_back(i);
      cnt[i] -= put;
      if (sub[idx].size() == c[i]) {
        idx++;
        if (idx > max_idx)
          max_idx++;
      }
    }
  }
  if (sub[max_idx].empty())
    max_idx--;
  cout << max_idx + 1 << endl;
  for (int i = 0; i <= max_idx; ++i) {
    cout << sub[i].size() << " ";
    for (int j : sub[i])
      cout << j << " ";
    cout << endl;
  }
}