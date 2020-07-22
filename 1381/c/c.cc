#include <cstdio>
#include <iostream>
#include <queue>
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
    int n, x, y;
    read(n), read(x), read(y);
    vector<int> a(n);
    vector<vector<int>> cnt(n + 2);
    for (int i = 0; i < n; ++i) {
      read(a[i]);
      cnt[a[i]].emplace_back(i);
    }
    int xc = -1;
    for (int i = 1; i <= n + 1; ++i)
      if (cnt[i].empty()) {
        xc = i;
        break;
      }
    int npos = y - x;
    if (x + npos > n) {
      printf("NO\n");
      return;
    }
    vector<int> ans(n);
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n + 1; ++i) {
      if (!cnt[i].empty())
        pq.push({(int)cnt[i].size(), i});
    }
    while (x--) {
      pair<int, int> top = pq.top();
      pq.pop();
      int color = top.second;
      ans[cnt[color].back()] = color;
      cnt[color].pop_back();
      if (!cnt[color].empty())
        pq.push({(int)cnt[color].size(), color});
    }
    while (npos > 0) {
      pair<int, int> top = pq.top();
      pq.pop();
      if (pq.empty()) {
        printf("NO\n");
        return;
      }
      pair<int, int> second = pq.top();
      pq.pop();
      int tcolor = top.second, scolor = second.second;
      if (npos == 3 && cnt[tcolor].size() == 1 && cnt[scolor].size() == 1) {
        pair<int, int> third = pq.top();
        pq.pop();
        int pcolor = third.second;
        ans[cnt[tcolor].back()] = scolor;
        ans[cnt[scolor].back()] = pcolor;
        ans[cnt[pcolor].back()] = tcolor;
        cnt[tcolor].pop_back();
        cnt[scolor].pop_back();
        cnt[pcolor].pop_back();
        npos -= 3;
        continue;
      }
      if (npos == 1) {
        ans[cnt[tcolor].back()] = scolor;
        cnt[tcolor].pop_back();
      } else {
        ans[cnt[tcolor].back()] = scolor;
        ans[cnt[scolor].back()] = tcolor;
        cnt[tcolor].pop_back();
        cnt[scolor].pop_back();
      }
      if (!cnt[tcolor].empty())
        pq.push({(int)cnt[tcolor].size(), tcolor});
      if (!cnt[scolor].empty())
        pq.push({(int)cnt[scolor].size(), scolor});
      npos -= 2;
    }
    while (!pq.empty()) {
      pair<int, int> top = pq.top();
      pq.pop();
      for (int i : cnt[top.second])
        ans[i] = xc;
    }
    printf("YES\n");
    for (int i : ans)
      printf("%d ", i);
    printf("\n");
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