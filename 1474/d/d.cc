#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n))
    x++;
  return x;
}

int bsf(unsigned int n) {
#ifdef _MSC_VER
  unsigned long index;
  _BitScanForward(&index, n);
  return index;
#else
  return __builtin_ctz(n);
#endif
}

} // namespace internal

} // namespace atcoder

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct lazy_segtree {
public:
  lazy_segtree() : lazy_segtree(0) {}
  explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
  explicit lazy_segtree(const std::vector<S> &v) : _n(int(v.size())) {
    log = internal::ceil_pow2(_n);
    size = 1 << log;
    d = std::vector<S>(2 * size, e());
    lz = std::vector<F>(size, id());
    for (int i = 0; i < _n; i++)
      d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--)
      push(p >> i);
    d[p] = x;
    for (int i = 1; i <= log; i++)
      update(p >> i);
  }

  S get(int p) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--)
      push(p >> i);
    return d[p];
  }

  S prod(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    if (l == r)
      return e();

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l)
        push(l >> i);
      if (((r >> i) << i) != r)
        push(r >> i);
    }

    S sml = e(), smr = e();
    while (l < r) {
      if (l & 1)
        sml = op(sml, d[l++]);
      if (r & 1)
        smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }

    return op(sml, smr);
  }

  S all_prod() { return d[1]; }

  void apply(int p, F f) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--)
      push(p >> i);
    d[p] = mapping(f, d[p]);
    for (int i = 1; i <= log; i++)
      update(p >> i);
  }
  void apply(int l, int r, F f) {
    assert(0 <= l && l <= r && r <= _n);
    if (l == r)
      return;

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l)
        push(l >> i);
      if (((r >> i) << i) != r)
        push((r - 1) >> i);
    }

    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1)
          all_apply(l++, f);
        if (r & 1)
          all_apply(--r, f);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }

    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l)
        update(l >> i);
      if (((r >> i) << i) != r)
        update((r - 1) >> i);
    }
  }

  template <bool (*g)(S)> int max_right(int l) {
    return max_right(l, [](S x) { return g(x); });
  }
  template <class G> int max_right(int l, G g) {
    assert(0 <= l && l <= _n);
    assert(g(e()));
    if (l == _n)
      return _n;
    l += size;
    for (int i = log; i >= 1; i--)
      push(l >> i);
    S sm = e();
    do {
      while (l % 2 == 0)
        l >>= 1;
      if (!g(op(sm, d[l]))) {
        while (l < size) {
          push(l);
          l = (2 * l);
          if (g(op(sm, d[l]))) {
            sm = op(sm, d[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = op(sm, d[l]);
      l++;
    } while ((l & -l) != l);
    return _n;
  }

  template <bool (*g)(S)> int min_left(int r) {
    return min_left(r, [](S x) { return g(x); });
  }
  template <class G> int min_left(int r, G g) {
    assert(0 <= r && r <= _n);
    assert(g(e()));
    if (r == 0)
      return 0;
    r += size;
    for (int i = log; i >= 1; i--)
      push((r - 1) >> i);
    S sm = e();
    do {
      r--;
      while (r > 1 && (r % 2))
        r >>= 1;
      if (!g(op(d[r], sm))) {
        while (r < size) {
          push(r);
          r = (2 * r + 1);
          if (g(op(d[r], sm))) {
            sm = op(d[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = op(d[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

private:
  int _n, size, log;
  std::vector<S> d;
  std::vector<F> lz;

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  void all_apply(int k, F f) {
    d[k] = mapping(f, d[k]);
    if (k < size)
      lz[k] = composition(f, lz[k]);
  }
  void push(int k) {
    all_apply(2 * k, lz[k]);
    all_apply(2 * k + 1, lz[k]);
    lz[k] = id();
  }
};

} // namespace atcoder

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

struct S {
  ll a;
};

struct F {
  ll v;
};

S op(S l, S r) { return S{min(l.a, r.a)}; }

S e() { return S{0}; }

S mapping(F l, S r) { return S{r.a + l.v}; }

F composition(F l, F r) { return F{l.v + r.v}; }

F id() { return F{0}; }

class Solution {
public:
  void solve() {
    int n;
    read(n);
    vector<ll> a(n);
    ll sum = 0, even = 0, odd = 0;
    for (int i = 0; i < n; ++i) {
      read(a[i]);
      sum += a[i];
      if (i % 2 == 0)
        even += a[i];
    }
    if (sum % 2 != 0) {
      printf("NO\n");
      return;
    }
    odd = sum - even;
    vector<S> E((n + 1) / 2);
    vector<S> O(n / 2);
    ll last = 0;
    for (int i = 0; i < n; ++i) {
      ll rem = a[i] - last;
      last = rem;
      if (i % 2 == 0) {
        E[i / 2] = {rem};
      } else {
        O[i / 2] = {rem};
      }
    }

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> e(E), o(O);

    if (odd == even && e.all_prod().a >= 0 && o.all_prod().a >= 0) {
      printf("YES\n");
      return;
    }

    for (int i = 0; i < n - 1; ++i) {
      ll delta = a[i] - a[i + 1];
      if (i % 2 == 0) {
        if (even - delta != odd + delta)
          continue;
        e.apply(i / 2, {-delta});
        e.apply(i / 2 + 1, (int)E.size(), {-delta * 2});
        o.apply(i / 2, (int)O.size(), {delta * 2});
        if (e.all_prod().a >= 0 && o.all_prod().a >= 0) {
          printf("YES\n");
          return;
        }
        e.apply(i / 2, {delta});
        e.apply(i / 2 + 1, (int)E.size(), {delta * 2});
        o.apply(i / 2, (int)O.size(), {-delta * 2});
      } else {
        if (odd - delta != even + delta)
          continue;
        o.apply(i / 2, {-delta});
        e.apply(i / 2 + 1, (int)E.size(), {delta * 2});
        o.apply(i / 2 + 1, (int)O.size(), {-delta * 2});
        if (e.all_prod().a >= 0 && o.all_prod().a >= 0) {
          printf("YES\n");
          return;
        }
        o.apply(i / 2, {delta});
        e.apply(i / 2 + 1, (int)E.size(), {-delta * 2});
        o.apply(i / 2 + 1, (int)O.size(), {delta * 2});
      }
    }

    printf("NO\n");
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}