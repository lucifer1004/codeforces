#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define MAX 100000

class Solution {
  int mu[MAX + 5], cnt[MAX + 5];
  ll ans = 0;
  bool exist[MAX + 5];
  vi d[MAX + 5];

  void init() {
    for (int i = 1; i <= MAX; ++i) {
      for (int j = i; j <= MAX; j += i) {
        d[j].push_back(i);
      }
      if (i == 1)
        mu[i] = 1;
      else {
        int first_non_one = d[i][1];
        int quotient = i / first_non_one;
        if (quotient % first_non_one == 0)
          mu[i] = 0;
        else
          mu[i] = -mu[quotient];
      }
    }
  }

  void input() {
    memset(exist, 0, sizeof(exist));

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      exist[a] = true;
      ans = max(ans, (ll)a);
    }
  }

  void update(int i, int delta) {
    for (int j : d[i]) {
      cnt[j] += delta;
    }
  }

  bool coprime_exist(int i) {
    int coprime_count = 0;
    for (int j : d[i]) {
      coprime_count += mu[j] * cnt[j];
    }

    return coprime_count > 0;
  }

 public:
  void solve() {
    init();
    input();
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= MAX; ++i) {
      stack<int> st;
      for (int j = MAX / i; j >= 1; --j) {
        if (!exist[i * j]) continue;
        while (coprime_exist(j)) {
          ans = max(ans, (ll)i * j * st.top());
          update(st.top(), -1);
          st.pop();
        }

        update(j, 1);
        st.push(j);
      }

      while (!st.empty()) {
        update(st.top(), -1);
        st.pop();
      }
    }

    cout << ans;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}