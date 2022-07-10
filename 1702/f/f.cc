#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

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

class Solution {
 public:
  void solve() {
    int n;
    read(n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      read(a[i]);
      while (!(a[i] & 1)) a[i] >>= 1;
    }
    for (int i = 0; i < n; ++i) {
      read(b[i]);
      while (!(b[i] & 1)) b[i] >>= 1;
    }

    sort(a.begin(), a.end());
    int ptr = n - 1;

    priority_queue<int> pq(b.begin(), b.end());
    while (!pq.empty()) {
      if (pq.top() > a[ptr]) {
        int half = pq.top() >> 1;
        pq.pop();
        pq.push(half);
      } else if (pq.top() == a[ptr]) {
        pq.pop();
        --ptr;
      } else {
        printf("NO\n");
        return;
      }
    }

    printf("YES\n");
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