#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

void solve() {
  int n, p, k;
  cin >> n >> p >> k;
  vi a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  vi tsum(k + 1);
  for (int i = 0; i < k; ++i) {
    tsum[i + 1] = tsum[i] + a[i];
  }

  vvi sum(k, vi{0});
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j * k + i < n; ++j) {
      sum[i].push_back(sum[i][j] + a[j * k + i]);
    }
  }

  int ans = (int)(upper_bound(tsum.begin(), tsum.end(), p) - tsum.begin()) - 1;
  if (a[k - 1] <= p) ans = k;

  for (int i = 0; i < k; ++i) {
    for (int j = 1; j < sum[i].size(); ++j) {
      int s;
      if (i == k - 1) {
        s = sum[i][j];
        if (s > p) break;
        ans = max(ans, k * j);
      } else {
        s = sum[i][j] - a[i];
        if (s > p) break;
        int left = p - s;
        int more =
            (int)(upper_bound(tsum.begin(), tsum.end(), left) - tsum.begin()) -
            1;
        more = min(more, i + 1);
        ans = max(ans, k * (j - 1) + more);
      }
    }
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}