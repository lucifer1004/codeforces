#include <iostream>
#include <stack>
#include <vector>

#define MOD 1000000007

using namespace std;
typedef int64_t ll;
struct Segment {
  ll h, w;
};
stack<Segment> st;
ll ans = 0;

void insert(ll h, ll w) {
  if (st.empty() || st.top().h < h)
    st.push({h, w});
  else if (st.top().h == h)
    st.top().w += w;
}

void update(ll h, ll w, ll bh) {
  h %= MOD, w %= MOD;
  ll ch = h * (h + 1) / 2 % MOD;
  ll cw = w * (w + 1) / 2 % MOD;
  ll tot = ch * cw % MOD + cw * h % MOD * bh % MOD;
  ans = (ans + tot) % MOD;
}

int main() {
  int n;
  cin >> n;
  vector<ll> h(n + 1), w(n + 1);
  for (int i = 0; i < n; ++i)
    cin >> h[i];
  for (int i = 0; i < n; ++i)
    cin >> w[i];
  for (int i = 0; i <= n; ++i) {
    ll cw = w[i];
    while (!st.empty() && st.top().h > h[i]) {
      Segment first = st.top();
      st.pop();
      ll bh = h[i];
      if (!st.empty() && st.top().h > h[i]) {
        bh = st.top().h;
        insert(st.top().h, first.w);
      } else
        cw += first.w;
      ll dh = first.h - bh;
      update(dh, first.w, bh);
    }
    insert(h[i], cw);
  }
  cout << ans;
}