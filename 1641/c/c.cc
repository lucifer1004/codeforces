#include <array>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
#define MAXN 200005
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)

using namespace std;

template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

struct Node {
  // last_healthy: the largest time of all healthy people within this
  // segment.
  int l, r, healthy_count, last_healthy;
  bool lazy;
} s[MAXN << 2]{};

int sick_time[MAXN]{};

void build(int idx, int l, int r) {
  s[idx].l = l, s[idx].r = r;
  s[idx].last_healthy = 0;
  if (l != r) {
    int mid = (l + r) >> 1;
    build(lson(idx), l, mid);
    build(rson(idx), mid + 1, r);
  }
}

void calc(int idx) {
  s[idx].healthy_count =
      s[lson(idx)].healthy_count + s[rson(idx)].healthy_count;
  s[idx].last_healthy =
      max(s[lson(idx)].last_healthy, s[rson(idx)].last_healthy);
}

void push_down(int idx) {
  if (s[idx].lazy) {
    for (int i = lson(idx); i <= rson(idx); i++) {
      if (s[i].healthy_count != s[i].r - s[i].l + 1) {
        s[i].lazy = true;
        s[i].healthy_count = s[i].r - s[i].l + 1;
        s[i].last_healthy = s[idx].last_healthy;
      }
    }
  }

  s[idx].lazy = false;
}

int query_healthy(int idx, int l, int r) {
  if (s[idx].l >= l && s[idx].r <= r) return s[idx].healthy_count;

  push_down(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  int ans = 0;
  if (l <= mid) ans += query_healthy(lson(idx), l, r);
  if (mid + 1 <= r) ans += query_healthy(rson(idx), l, r);

  return ans;
}

int query_last_healthy(int idx, int l, int r) {
  if (s[idx].l >= l && s[idx].r <= r) return s[idx].last_healthy;

  push_down(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  int ans = 0;
  if (l <= mid) ans = max(ans, query_last_healthy(lson(idx), l, r));
  if (mid + 1 <= r) ans = max(ans, query_last_healthy(rson(idx), l, r));

  return ans;
}

int find_sick(int l, int r) {
  if (l == r) return l;
  int mid = (l + r) >> 1;
  if (query_healthy(1, l, mid) == mid - l)
    return find_sick(l, mid);
  else
    return find_sick(mid + 1, r);
}

void update_healthy(int idx, int l, int r, int t) {
  if (s[idx].l >= l && s[idx].r <= r) {
    if (s[idx].healthy_count != s[idx].r - s[idx].l + 1) {
      s[idx].healthy_count = s[idx].r - s[idx].l + 1;
      s[idx].last_healthy = t;
      s[idx].lazy = true;
    }

    return;
  }

  push_down(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (l <= mid) update_healthy(lson(idx), l, r, t);
  if (mid + 1 <= r) update_healthy(rson(idx), l, r, t);
  calc(idx);
}

class Solution {
 public:
  void solve() {
    int n, q;
    read(n), read(q);

    build(1, 1, n);
    memset(sick_time, 0x3f, sizeof(sick_time));

    vector<array<int, 3>> queries(q + 1);
    for (int i = 1; i <= q; i++) {
      int t;
      read(t);

      if (t == 0) {
        int l, r, x;
        read(queries[i][0]), read(queries[i][1]), read(queries[i][2]);
      } else {
        int j;
        read(queries[i][0]);
        queries[i][1] = queries[i][2] = -1;
      }
    }

    for (int i = 1; i <= q; ++i) {
      if (queries[i][2] == 0) {
        update_healthy(1, queries[i][0], queries[i][1], i);
      }
    }

    for (int i = 1; i <= q; ++i) {
      if (queries[i][2] == 1) {
        int l = queries[i][0], r = queries[i][1];
        if (query_healthy(1, l, r) == r - l) {
          int p = find_sick(l, r);
          sick_time[p] = min(sick_time[p], max(i, query_last_healthy(1, l, r)));
        }
      }
    }

    for (int i = 1; i <= q; ++i) {
      if (queries[i][2] == -1) {
        int p = queries[i][0];

        if (sick_time[p] < i) {
          printf("YES\n");
        } else {
          int healthy_time = query_last_healthy(1, p, p);
          if (healthy_time == 0 || healthy_time > i)
            printf("N/A\n");
          else
            printf("NO\n");
        }
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}