#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 8007

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n), s(n + 1), cnt(n + 1);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      s[i + 1] = s[i] + a[i];
      int l = 0;
      if (s[i + 1] > n)
        l = distance(s.begin(),
                     lower_bound(s.begin(), s.begin() + i + 1, s[i + 1] - n));
      for (int j = l; j < i; ++j) {
        int delta = s[i + 1] - s[j];
        if (cnt[delta] > 0) {
          ans += cnt[delta];
          cnt[delta] = 0;
        }
      }
    }
    printf("%d\n", ans);
  }
}