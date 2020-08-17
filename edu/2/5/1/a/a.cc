#include <iostream>
#define MAXN 100005

using namespace std;
typedef long long ll;
inline int lowbit(int x) { return x & (-x); }
int n, m;
ll a[MAXN];
ll query(int idx) {
  ll ans = 0;
  for (; idx > 0; idx -= lowbit(idx))
    ans += a[idx];
  return ans;
}
void update(int idx, ll delta) {
  for (; idx <= n; idx += lowbit(idx))
    a[idx] += delta;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int t, l, r, x, v;
    cin >> t;
    if (t == 1) {
      cin >> l >> r >> v;
      update(l + 1, v);
      update(r + 1, -v);
    } else {
      cin >> x;
      cout << query(x + 1) << endl;
    }
  }
}