#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
  int calc(int a, int b, int h) {
    int turns = (h - 1) / (a + b);
    h -= turns * (a + b);
    return (h - 1) / a;
  }

public:
  void solve() {
    int n, a, b, k;
    scanf("%d%d%d%d", &n, &a, &b, &k);
    int sum = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
      int h;
      scanf("%d", &h);
      int t = calc(a, b, h);
      if (t + sum <= k) {
        pq.push(t);
        sum += t;
      } else if (!pq.empty() && t < pq.top()) {
        sum += t - pq.top();
        pq.pop();
        pq.push(t);
      }
    }
    printf("%d", (int)pq.size());
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}