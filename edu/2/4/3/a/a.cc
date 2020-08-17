#include <cstring>
#include <iostream>
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
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cout << query(n) - query(x - 1) << " ";
    update(x, 1);
  }
}