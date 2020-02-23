#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<int> h(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &h[i]);
    vector<ll> l(n), r(n);
    stack<pair<ll, ll>> st;
    st.push(make_pair(h[0], 1));
    ll sum = h[0];
    for (int i = 1; i < n; ++i) {
      ll count = 1;
      while (!st.empty() && h[i] < st.top().first) {
        count += st.top().second;
        sum -= st.top().first * st.top().second;
        st.pop();
      }
      st.push(make_pair(h[i], count));
      sum += h[i] * count;
      l[i] = sum - h[i];
    }

    sum = h[n - 1];
    st = stack<pair<ll, ll>>();
    st.push(make_pair(h[n - 1], 1));
    for (int i = n - 2; i >= 0; --i) {
      ll count = 1;
      while (!st.empty() && h[i] < st.top().first) {
        count += st.top().second;
        sum -= st.top().first * st.top().second;
        st.pop();
      }
      st.push(make_pair(h[i], count));
      sum += h[i] * count;
      r[i] = sum - h[i];
    }

    ll ans = 0, idx = -1;
    for (int i = 0; i < n; ++i) {
      ll val = l[i] + r[i] + h[i];
      if (val > ans) {
        ans = val;
        idx = i;
      }
    }

    for (int i = idx - 1; i >= 0; --i)
      h[i] = min(h[i], h[i + 1]);
    for (int i = idx + 1; i < n; ++i)
      h[i] = min(h[i], h[i - 1]);

    for (int i : h)
      printf("%d ", i);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}