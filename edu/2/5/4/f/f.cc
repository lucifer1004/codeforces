#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#define MAXN 400005
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

struct Node {
  int l, r, L, R, x = 0, hi = 0, start = 0, end = 0, add = 0;
  bool lazy = false;
} s[MAXN << 2];
vector<int> vpos;

void build(int idx, int l, int r) {
  s[idx].l = l, s[idx].r = r;
  s[idx].L = l == 1 ? 1 : vpos[l - 2] + 1, s[idx].R = vpos[r - 1];
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  build(lson, l, mid);
  build(rson, mid + 1, r);
}

void calc(int idx) {
  s[idx].hi = max(s[lson].hi, s[rson].hi);
  s[idx].start = s[lson].start;
  s[idx].end = s[rson].end;
}

void assign(int idx, int lstart, int lno, int x) {
  s[idx].start = lstart + (s[idx].L - lno - 1) * x;
  s[idx].end = s[idx].start + x * (s[idx].R - s[idx].L + 1);
  s[idx].hi = max(s[idx].start, s[idx].end);
  s[idx].lazy = true;
  s[idx].add = 0;
  s[idx].x = x;
}

void update(int idx, int x) {
  s[idx].start += x;
  s[idx].end += x;
  s[idx].hi += x;
  s[idx].add += x;
}

void pushdown(int idx) {
  if (s[idx].lazy) {
    assign(lson, s[idx].start, s[idx].L - 1, s[idx].x);
    assign(rson, s[lson].end, s[rson].L - 1, s[idx].x);
    s[idx].add = 0;
  }
  if (s[idx].add)
    for (int i = lson; i <= rson; ++i)
      update(i, s[idx].add);
  s[idx].lazy = false;
  s[idx].add = 0;
}

Node get(int idx, int pos) {
  if (s[idx].l == pos && s[idx].r == pos)
    return s[idx];
  pushdown(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (pos <= mid)
    return get(lson, pos);
  return get(rson, pos);
}

void assign(int idx, int l, int r, int lstart, int lno, int x) {
  if (s[idx].l >= l && s[idx].r <= r) {
    assign(idx, lstart, lno, x);
    return;
  }
  pushdown(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (l <= mid)
    assign(lson, l, r, lstart, lno, x);
  if (mid + 1 <= r)
    assign(rson, l, r, lstart, lno, x);
  calc(idx);
}

void update(int idx, int l, int r, int x) {
  if (s[idx].l >= l && s[idx].r <= r) {
    update(idx, x);
    return;
  }
  pushdown(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (l <= mid)
    update(lson, l, r, x);
  if (mid + 1 <= r)
    update(rson, l, r, x);
  calc(idx);
}

int query(int idx, int l, int r) {
  if (s[idx].l >= l && s[idx].r <= r)
    return s[idx].hi;
  pushdown(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  int ans = 0;
  if (l <= mid)
    ans = max(ans, query(lson, l, r));
  if (mid + 1 <= r)
    ans = max(ans, query(rson, l, r));
  return ans;
}

int main() {
  int n;
  read(n);
  char c;
  vector<vector<int>> operations;
  set<int> pos;
  while ((c = getchar()) != 'E') {
    int m = c == 'Q' ? 1 : 3;
    vector<int> params(m);
    for (int i = 0; i < m; ++i)
      read(params[i]);
    if (m == 3) {
      pos.insert(params[0]), pos.insert(params[1]);
      if (params[0] > 1)
        pos.insert(params[0] - 1);
      if (params[1] < n)
        pos.insert(params[1] + 1);
    }
    operations.emplace_back(params);
  }
  pos.insert(n);
  vpos = vector<int>(pos.begin(), pos.end());
  int m = vpos.size();
  map<int, int> dict;
  for (int i = 0; i < m; ++i)
    dict[vpos[i]] = i + 1;
  build(1, 1, m);
  string ans;
  for (vector<int> &op : operations) {
    if (op.size() == 3) {
      int l = dict[op[0]], r = dict[op[1]], d = op[2];
      int lstart, lno;
      if (l == 1) {
        lstart = 0;
        lno = 0;
      } else {
        Node last = get(1, l - 1);
        lstart = last.end;
        lno = last.R;
      }
      int rend0 = get(1, r).end;
      assign(1, l, r, lstart, lno, d);
      if (r < m) {
        int rend = get(1, r).end;
        int delta = rend - rend0;
        update(1, r + 1, m, delta);
      }
    } else {
      int l = 1, r = m;
      while (l <= r) {
        int mid = (l + r) >> 1;
        int hi = query(1, 1, mid);
        if (hi > op[0])
          r = mid - 1;
        else
          l = mid + 1;
      }
      int res;
      if (r == m)
        res = n;
      else {
        Node nxt = get(1, r + 1);
        int step = (nxt.end - nxt.start) / (nxt.R - nxt.L + 1);
        int extra = (op[0] - nxt.start) / step;
        res = nxt.L + extra - 1;
      }
      ans += to_string(res) + "\n";
    }
  }
  printf("%s", ans.c_str());
}