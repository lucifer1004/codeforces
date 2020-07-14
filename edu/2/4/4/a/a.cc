#include <cstring>
#include <iostream>
#include <vector>
#define MAXN 100005

using namespace std;
inline int lowbit(int x) { return x & (-x); }
int n, m;
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
  vector<int> seq(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> seq[i];
    if (i % 2 == 0)
      seq[i] = -seq[i];
    update(i, seq[i]);
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int op, v1, v2;
    cin >> op >> v1 >> v2;
    if (op == 0) {
      if (seq[v1] > 0)
        update(v1, v2 - seq[v1]);
      else
        update(v1, -seq[v1] - v2);
      seq[v1] = v1 % 2 == 1 ? v2 : -v2;
    } else {
      int ans = query(v2) - query(v1 - 1);
      if (v1 % 2 == 0)
        ans = -ans;
      cout << ans << endl;
    }
  }
}