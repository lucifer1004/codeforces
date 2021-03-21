#include <climits>
#include <cstdio>
#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;
typedef long long ll;

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
    vector<int> h(n), b(n);
    for (int i = 0; i < n; ++i) read(h[i]);
    for (int i = 0; i < n; ++i) read(b[i]);

    vector<ll> dp(n, LLONG_MIN);
    dp[0] = b[0];
    set<pair<ll, int>, greater<>> pq;
    pq.emplace(b[0], 0);
    stack<int> st;
    st.push(0);

    for (int i = 1; i < n; ++i) {
      dp[i] = pq.begin()->first + b[i];
      while (!st.empty() && h[st.top()] > h[i]) {
        int idx = st.top();
        st.pop();
        dp[i] = max(dp[i], dp[idx] - b[idx] + b[i]);
        pq.erase({dp[idx], idx});
      }
      pq.emplace(dp[i], i);
      st.push(i);
    }

    ll ans = LLONG_MIN;
    while (!st.empty()) {
      ans = max(ans, dp[st.top()]);
      st.pop();
    }

    printf("%lld", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}