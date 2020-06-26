#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#define INF 0x3f3f3f3f
#define MAXN 400005

using namespace std;
typedef long long ll;

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

int n, k, m;
struct {
  int data = 0, lazy = 0, l = 0, r = 0;
} s[MAXN * 4];
void calc(int idx) {
  s[idx].data = min(s[idx << 1].data, s[idx << 1 | 1].data);
}
void build(int idx, int l, int r) {
  s[idx].l = l, s[idx].r = r;
  if (l == r) {
    s[idx].data = n - l + 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(idx << 1, l, mid);
  build(idx << 1 | 1, mid + 1, r);
  calc(idx);
}
void push_down(int idx) {
  if (s[idx].lazy == 0)
    return;
  for (int i = idx << 1; i <= (idx << 1 | 1); ++i) {
    s[i].data += s[idx].lazy;
    s[i].lazy += s[idx].lazy;
  }
  calc(idx);
  s[idx].lazy = 0;
}
void update(int idx, int l, int r, int x) {
  if (s[idx].l >= l && s[idx].r <= r) {
    s[idx].data += x;
    s[idx].lazy += x;
    return;
  }
  push_down(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (l <= mid)
    update(idx << 1, l, r, x);
  if (mid < r)
    update(idx << 1 | 1, l, r, x);
  calc(idx);
}
int query(int idx, int l, int r) {
  if (s[idx].l >= l && s[idx].r <= r)
    return s[idx].data;
  int ans = INF;
  push_down(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (l <= mid)
    ans = min(ans, query(idx << 1, l, r));
  if (mid < r)
    ans = min(ans, query(idx << 1 | 1, l, r));
  return ans;
}

class Solution {
public:
  void solve() {
    read(n), read(k), read(m);
    build(1, 1, n * 2);
    set<pair<int, int>> st;
    map<int, int, greater<>> cnt;

    for (int i = 0; i < m; ++i) {
      int x, y;
      read(x), read(y);
      int pos = abs(x - k) + y;
      if (st.count({x, y})) {
        st.erase({x, y});
        cnt[pos]--;
        if (cnt[pos] == 0)
          cnt.erase(pos);
        update(1, 1, pos, 1);
      } else {
        st.insert({x, y});
        cnt[pos]++;
        update(1, 1, pos, -1);
      }
      int up = cnt.empty() ? n : cnt.begin()->first;
      cout << max(0, -query(1, 1, up)) << endl;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}