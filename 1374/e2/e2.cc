#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

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

class Solution {
public:
  void solve() {
    int n, m, k;
    read(n), read(m), read(k);
    vector<pair<int, int>> a, b, ab;
    set<pair<int, int>> now, rest;
    set<pair<int, int>, greater<>> top;
    int asum = 0, bsum = 0, absum = 0, cnow = 0, ctop = 0;
    for (int i = 0; i < n; ++i) {
      int ti, ai, bi;
      read(ti), read(ai), read(bi);
      asum += ai;
      bsum += bi;
      absum += ai && bi;
      top.insert({ti, i});
      ctop += ti;
      if (ai && bi)
        ab.emplace_back(ti, i);
      else if (ai)
        a.emplace_back(ti, i);
      else if (bi)
        b.emplace_back(ti, i);
    }
    if (asum < k || bsum < k || 2 * k - absum > m) {
      printf("-1");
      return;
    }
    set<pair<int, int>, greater<>> rawtop(top);
    int rctop = ctop;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(ab.begin(), ab.end());
    int ans = INT_MAX, start = min(k, (int)ab.size());
    auto output = [&]() {
      printf("%d\n", cnow + ctop);
      for (auto p : now)
        printf("%d ", p.second + 1);
      for (auto p : top)
        printf("%d ", p.second + 1);
    };
    auto work = [&](bool first_run) {
      // Initial status: use $start$ ab and $k-start$ a and $k-start$ b.
      for (int i = 0; i < start; ++i) {
        cnow += ab[i].first;
        ctop -= ab[i].first;
        now.insert(ab[i]);
        top.erase(ab[i]);
      }
      for (int i = 0; i < k - start; ++i) {
        cnow += a[i].first + b[i].first;
        ctop -= a[i].first + b[i].first;
        now.insert(a[i]);
        now.insert(b[i]);
        top.erase(a[i]);
        top.erase(b[i]);
      }
      int need = m - (2 * k - start);
      while (top.size() > need) {
        pair<int, int> p = *top.begin();
        ctop -= p.first;
        top.erase(p);
        rest.insert(p);
      }
      if (first_run)
        ans = min(ans, cnow + ctop);
      else if (cnow + ctop == ans) {
        output();
        return;
      }
      for (int i = start - 1; i >= 0 && 2 * k - i <= m; --i) {
        if (a.size() < k - i || b.size() < k - i)
          break;
        cnow -= ab[i].first;
        now.erase(ab[i]);
        if (top.empty() || top.begin()->first < ab[i].first)
          rest.insert(ab[i]);
        else {
          top.insert(ab[i]);
          ctop += ab[i].first;
        }
        now.insert(a[k - i - 1]);
        now.insert(b[k - i - 1]);
        cnow += a[k - i - 1].first + b[k - i - 1].first;
        if (rest.count(a[k - i - 1]))
          rest.erase(a[k - i - 1]);
        else {
          top.erase(a[k - i - 1]);
          ctop -= a[k - i - 1].first;
        }
        if (rest.count(b[k - i - 1]))
          rest.erase(b[k - i - 1]);
        else {
          top.erase(b[k - i - 1]);
          ctop -= b[k - i - 1].first;
        }
        int need = m - (2 * k - i);
        while (top.size() > need) {
          pair<int, int> p = *top.begin();
          ctop -= p.first;
          top.erase(p);
          rest.insert(p);
        }
        while (top.size() < need) {
          pair<int, int> p = *rest.begin();
          ctop += p.first;
          rest.erase(p);
          top.insert(p);
        }
        if (first_run)
          ans = min(ans, cnow + ctop);
        else if (cnow + ctop == ans) {
          output();
          return;
        }
      }
    };
    auto restore = [&]() {
      cnow = 0, ctop = rctop;
      now.clear();
      rest.clear();
      top = rawtop;
    };

    work(true);
    // We need to restore the answer.
    // First, restore relevant variables.
    restore();
    // Then, do it again.
    work(false);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}