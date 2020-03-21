#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::string s, t;
  std::cin >> s >> t;
  if (s.size() < t.size()) {
    std::cout << 0;
    return 0;
  }
  int n = t.size();
  std::vector<int> pi(n);
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j != 0 && t[i] != t[j])
      j = pi[j - 1];
    pi[i] = t[i] == t[j] ? j + 1 : 0;
  }

  std::vector<int> dp(n + 1, -1);
  dp[0] = 0;
  for (int i = 0; i < s.size(); ++i) {
    for (int j = n - 1; j >= 0; --j) {
      dp[j + 1] = -1;
      if (dp[j] != -1 && (s[i] == t[j] || s[i] == '?'))
        dp[j + 1] = dp[j] + (j == n - 1);
    }
    int j = n;
    while (j != 0) {
      int last = pi[j - 1];
      dp[last] = std::max(dp[last], dp[j]);
      j = last;
    }
  }
  std::cout << *std::max_element(dp.begin(), dp.end());
}