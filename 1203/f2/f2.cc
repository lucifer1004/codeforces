#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, r;
  cin >> n >> r;
  vector<pair<int, int>> good, bad;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    if (b >= 0)
      good.emplace_back(a, b);
    else
      bad.emplace_back(a, b);
  }
  int good_count = 0;
  sort(good.begin(), good.end());
  for (auto [require, delta] : good) {
    if (require > r)
      break;
    r += delta;
    good_count++;
  }
  sort(bad.begin(), bad.end(), [](pair<int, int> a, pair<int, int> b) {
    return a.first + a.second > b.first + b.second;
  });
  vector<int> dp(r + 1);
  for (auto [require, delta] : bad)
    for (int i = max(require, -delta); i <= r; ++i)
      dp[i + delta] = max(dp[i + delta], dp[i] + 1);
  int bad_count = *max_element(dp.begin(), dp.end());
  cout << good_count + bad_count;
}