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
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  vector<int> ans(n);
  for (int i = n - 1; i >= 0; --i) {
    int idx = n - a[i];
    ans[i] = idx + query(idx);
  }
}