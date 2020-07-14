#include <cstring>
#include <iostream>
#include <vector>
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
void update(int idx, int delta) {
  for (; idx <= n; idx += lowbit(idx))
    a[idx] += delta;
}
int main() {
  memset(a, 0, sizeof(a));
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      l++;
      update(l, v);
      update(r + 1, -v);
    } else {
      int idx;
      cin >> idx;
      cout << query(idx + 1) << endl;
    }
  }
}