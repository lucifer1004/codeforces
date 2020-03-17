#include <cstdio>
#include <stack>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  vector<ll> left_lo(n), right_lo(n), left_hi(n), right_hi(n);
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && a[st.top()] > a[i]) {
      right_lo[st.top()] += i - st.top() - 1;
      st.pop();
    }
    st.push(i);
  }
  while (!st.empty()) {
    right_lo[st.top()] += n - st.top() - 1;
    st.pop();
  }
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && a[st.top()] >= a[i]) {
      left_lo[st.top()] += st.top() - i - 1;
      st.pop();
    }
    st.push(i);
  }
  while (!st.empty()) {
    left_lo[st.top()] += st.top();
    st.pop();
  }
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && a[st.top()] < a[i]) {
      right_hi[st.top()] += i - st.top() - 1;
      st.pop();
    }
    st.push(i);
  }
  while (!st.empty()) {
    right_hi[st.top()] += n - st.top() - 1;
    st.pop();
  }
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && a[st.top()] <= a[i]) {
      left_hi[st.top()] += st.top() - i - 1;
      st.pop();
    }
    st.push(i);
  }
  while (!st.empty()) {
    left_hi[st.top()] += st.top();
    st.pop();
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll hi = (left_hi[i] + 1) * (right_hi[i] + 1);
    ll lo = (left_lo[i] + 1) * (right_lo[i] + 1);
    ans += (hi - lo) * a[i];
  }
  printf("%lld", ans);
}