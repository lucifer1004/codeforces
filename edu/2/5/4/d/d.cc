#include <cstdio>
#include <iostream>
#define MAXN 100005
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

int n, m, a[MAXN];
struct Node {
  int l, r;
  ll sum = 0, add = 0, fold;
} p[MAXN << 2], q[MAXN << 2];

void calc(Node *s, int idx) { s[idx].sum = s[lson].sum + s[rson].sum; }

void build(Node *s, int idx, int l, int r) {
  s[idx].l = l, s[idx].r = r;
  s[idx].fold = s == p ? r - l + 1 : (ll)(l + r) * (r - l + 1) / 2;
  if (l == r) {
    s[idx].sum = s == p ? a[l] : a[l] * l;
    return;
  }
  int mid = (l + r) >> 1;
  build(s, lson, l, mid);
  build(s, rson, mid + 1, r);
  calc(s, idx);
}

void pushdown(Node *s, int idx) {
  if (s[idx].add) {
    for (int i = lson; i <= rson; ++i) {
      s[i].sum += s[idx].add * s[i].fold;
      s[i].add += s[idx].add;
    }
  }
  s[idx].add = 0;
}

void update(Node *s, int idx, int l, int r, ll x) {
  if (s[idx].l >= l && s[idx].r <= r) {
    s[idx].sum += x * s[idx].fold;
    s[idx].add += x;
    return;
  }
  pushdown(s, idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (mid >= l)
    update(s, lson, l, r, x);
  if (mid + 1 <= r)
    update(s, rson, l, r, x);
  calc(s, idx);
}

ll query(Node *s, int idx, int l, int r) {
  if (s[idx].l >= l && s[idx].r <= r)
    return s[idx].sum;
  pushdown(s, idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  ll ans = 0;
  if (mid >= l)
    ans += query(s, lson, l, r);
  if (mid + 1 <= r)
    ans += query(s, rson, l, r);
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  read(n), read(m);
  for (int i = 1; i <= n; ++i)
    read(a[i]);
  build(p, 1, 1, n);
  build(q, 1, 1, n);

  string ans;
  for (int i = 0; i < m; ++i) {
    int t, l, r, d;
    read(t), read(l), read(r);
    if (t == 1) {
      read(d);
      update(p, 1, l, r, d);
      update(q, 1, l, r, d);
    } else {
      ll R = query(q, 1, 1, r);
      ll L = l == 1 ? 0 : query(q, 1, 1, l - 1);
      ll T = query(p, 1, l, r);
      ll res = R - L - T * (l - 1);
      ans += to_string(res) + "\n";
    }
  }
  printf("%s", ans.c_str());
}