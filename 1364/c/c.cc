#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    vector<int> b(n);
    stack<int> flex;
    int lo = 0;
    for (int i = 0; i < n; ++i) {
      flex.push(i);
      b[i] = 1e6;
      while (a[i] > lo) {
        if (flex.empty()) {
          printf("-1");
          return;
        }
        b[flex.top()] = lo++;
        flex.pop();
      }
    }
    for (int i = 0; i < n; ++i)
      printf("%d ", b[i]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}