#include <cstring>
#include <iostream>
#include <vector>
#define MAXN 100005

using namespace std;
inline int lowbit(int x) { return x & (-x); }
int n;
int a[MAXN];
int query(int idx) {
  int ans = 0;
  for (; idx > 0; idx -= lowbit(idx))
    ans += a[idx];
  return ans;
}
void update(int idx, int delta) {
  for (; idx <= n; idx += lowbit(idx))
    a[idx] += delta;
}
int main() {
  memset(a, 0, sizeof(a));
  cin >> n;
  vector<int> seq(n * 2), first(n + 1), ans(n + 1);
  int idx = 0;
  for (int i = 0; i < n * 2; ++i) {
    cin >> seq[i];
    if (!first[seq[i]]) {
      first[seq[i]] = ++idx;
      ans[seq[i]] = query(first[seq[i]] - 1);
      update(first[seq[i]], 1);
    } else {
      update(first[seq[i]], -1);
      ans[seq[i]] += query(n) - 2 * query(first[seq[i]] - 1);
    }
  }
  for (int i = 1; i <= n; ++i)
    cout << ans[i] << " ";
}