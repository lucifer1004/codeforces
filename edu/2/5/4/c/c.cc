#include <climits>
#include <cstdio>
#include <iostream>
#define MAXN 1000000
#define OFFSET 500001
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
  int l, r, seg = 0, len = 0, prefix = 0, suffix = 0;
  bool white = false, black = false;
} s[(MAXN + 5) << 2];

void calc(int idx) {
  s[idx].len = s[lson].len + s[rson].len;
  s[idx].prefix = s[lson].prefix;
  if (s[lson].prefix == s[lson].r - s[lson].l + 1)
    s[idx].prefix += s[rson].prefix;
  s[idx].suffix = s[rson].suffix;
  if (s[rson].suffix == s[rson].r - s[rson].l + 1)
    s[idx].suffix += s[lson].suffix;
  s[idx].seg = s[lson].seg + s[rson].seg;
  if (s[lson].suffix > 0 && s[rson].prefix > 0)
    s[idx].seg--;
}

void build(int idx, int l, int r) {
  s[idx].l = l, s[idx].r = r;
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  build(lson, l, mid);
  build(rson, mid + 1, r);
}

void fill(int idx) {
  s[idx].seg = 1;
  s[idx].prefix = s[idx].suffix = s[idx].len = s[idx].r - s[idx].l + 1;
  s[idx].black = true;
  s[idx].white = false;
}

void erase(int idx) {
  s[idx].seg = 0;
  s[idx].prefix = s[idx].suffix = s[idx].len = 0;
  s[idx].black = false;
  s[idx].white = true;
}

void pushdown(int idx) {
  if (s[idx].white)
    for (int i = lson; i <= rson; ++i)
      erase(i);
  if (s[idx].black)
    for (int i = lson; i <= rson; ++i)
      fill(i);
  s[idx].white = false;
  s[idx].black = false;
}

void update(int idx, int l, int r, bool x) {
  if (s[idx].l >= l && s[idx].r <= r) {
    s[idx].black = x;
    s[idx].white = !x;
    if (x)
      fill(idx);
    else
      erase(idx);
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  read(m);
  build(1, 1, MAXN);
  string ans;
  for (int i = 0; i < m; ++i) {
    int x, l;
    char c = getchar();
    read(x), read(l);
    update(1, x + OFFSET, x + OFFSET + l - 1, c == 'B');
    ans += to_string(s[1].seg) + " " + to_string(s[1].len) + "\n";
  }
  printf("%s", ans.c_str());
}