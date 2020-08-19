#include <climits>
#include <cstdio>
#include <iostream>
#define MAXN 200005
#define lson (idx << 1)
#define rson (idx << 1 | 1)

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

int n, m;
struct Node {
  int l, r;
  ll sum = 0, add = 0;
} s[MAXN << 2];

void calc(int idx) { s[idx].sum = s[lson].sum + s[rson].sum; }

void build(int idx, int l, int r) {
  s[idx].l = l, s[idx].r = r;
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  build(lson, l, mid);
  build(rson, mid + 1, r);
}

void pushdown(int idx) {
  if (s[idx].add) {
    for (int i = lson; i <= rson; ++i)
      s[i].sum += s[idx].add * (s[i].r - s[i].l + 1), s[i].add += s[idx].add;
  }
  s[idx].add = 0;
}

void update(int idx, int l, int r, ll x) {
  if (s[idx].l >= l && s[idx].r <= r) {
    s[idx].sum += x * (s[idx].r - s[idx].l + 1);
    s[idx].add += x;
    return;
  }
  pushdown(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (mid >= l)
    update(lson, l, r, x);
  if (mid + 1 <= r)
    update(rson, l, r, x);
  calc(idx);
}

ll query(int idx, int l, int r) {
  if (s[idx].l >= l && s[idx].r <= r)
    return s[idx].sum;
  pushdown(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  ll ans = 0;
  if (mid >= l)
    ans += query(lson, l, r);
  if (mid + 1 <= r)
    ans += query(rson, l, r);
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  read(n), read(m);
  build(1, 1, n);
  string ans;
  for (int i = 0; i < m; ++i) {
    int t, l, r, x, a, d;
    read(t);
    if (t == 1) {
      read(l), read(r), read(a), read(d);
      update(1, l, l, a);
      if (r > l)
        update(1, l + 1, r, d);
      if (r + 1 <= n)
        update(1, r + 1, r + 1, -(ll)d * (r - l) - a);
    } else {
      read(x);
      ans += to_string(query(1, 1, x)) + "\n";
    }
  }
  printf("%s", ans.c_str());
}