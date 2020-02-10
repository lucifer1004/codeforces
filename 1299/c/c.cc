#include <cstdio>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct Node {
  ll sum, count;
  bool operator<=(const Node a) const {
    ll left = sum * a.count;
    ll right = a.sum * count;
    return left <= right;
  }

  void operator+=(const Node a) {
    sum += a.sum;
    count += a.count;
  }
};

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    deque<Node> ans;
    for (int i = 0; i < n; ++i) {
      Node current{a[i], 1};
      while (!ans.empty()) {
        if (current <= ans.back()) {
          current += ans.back();
          ans.pop_back();
        } else
          break;
      }
      ans.push_back(current);
    }
    while (!ans.empty()) {
      Node front = ans.front();
      for (int i = 0; i < front.count; ++i)
        printf("%.9f\n", (double)front.sum / front.count);
      ans.pop_front();
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}