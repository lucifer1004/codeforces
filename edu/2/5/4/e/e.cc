#include <cstdio>
#include <iostream>
#define MAXN 2000005
#define lson (idx << 1)
#define rson (idx << 1 | 1)

using namespace std;

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

int n, k;
struct Node {
  int l, r, lo = 0, hi = 0;
  bool lf = false, hf = false;
} s[MAXN << 2];

void calc(int idx) {
  s[idx].lo = min(s[lson].lo, s[rson].lo);
  s[idx].hi = max(s[lson].hi, s[rson].hi);
}

void build(int idx, int l, int r) {
  s[idx].l = l, s[idx].r = r;
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  build(lson, l, mid);
  build(rson, mid + 1, r);
}

void up(int idx, int x) {
  if (s[idx].lo < x) {
    s[idx].hf = true;
    s[idx].lo = x;
  }
  s[idx].hi = max(s[idx].hi, x);
}

void down(int idx, int x) {
  s[idx].lo = min(s[idx].lo, x);
  if (s[idx].hi > x) {
    s[idx].lf = true;
    s[idx].hi = x;
  }
}

void pushdown(int idx) {
  if (s[idx].lf)
    for (int i = lson; i <= rson; ++i)
      down(i, s[idx].hi);
  if (s[idx].hf)
    for (int i = lson; i <= rson; ++i)
      up(i, s[idx].lo);
  s[idx].lf = false;
  s[idx].hf = false;
}

void up(int idx, int l, int r, int x) {
  if (s[idx].l >= l && s[idx].r <= r) {
    up(idx, x);
    return;
  }
  pushdown(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (mid >= l)
    up(lson, l, r, x);
  if (mid + 1 <= r)
    up(rson, l, r, x);
  calc(idx);
}

void down(int idx, int l, int r, int x) {
  if (s[idx].l >= l && s[idx].r <= r) {
    down(idx, x);
    return;
  }
  pushdown(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (mid >= l)
    down(lson, l, r, x);
  if (mid + 1 <= r)
    down(rson, l, r, x);
  calc(idx);
}

int query(int idx, int pos) {
  if (s[idx].l == s[idx].r)
    return s[idx].lo;
  pushdown(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (pos <= mid)
    return query(lson, pos);
  return query(rson, pos);
}

int main() {
  read(n), read(k);
  build(1, 1, n);
  for (int i = 0; i < k; ++i) {
    int t, l, r, h;
    read(t), read(l), read(r), read(h);
    l++, r++;
    if (t == 1)
      up(1, l, r, h);
    else
      down(1, l, r, h);
  }
  string ans;
  for (int i = 1; i <= n; ++i)
    ans += to_string(query(1, i)) + "\n";
  printf("%s", ans.c_str());
}