#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  if (x > y)
    swap(x, y);

  int len = x + y;   // Segment length
  int mul = n / len; // Number of full segments
  int rem = n % len; // Number of remaining positions

  int mask = 1 << y;
  int ymask = 1 << (y - 1);
  int xmask = 1 << (x - 1);
  vector<int> dp(mask, -1);
  dp[0] = 0;

  for (int i = 0; i < len; ++i) {
    vector<int> ndp(mask, -1);
    int weight = i < rem ? (mul + 1) : mul;
    for (int j = 0; j < mask; ++j) {
      if (dp[j] == -1)
        continue;

      // Leave the next position blank.
      int nxt_blank = (j << 1) & (mask - 1);
      ndp[nxt_blank] = max(ndp[nxt_blank], dp[j]);

      // Check if the next position is banned.
      if ((j & xmask) || (j & ymask))
        continue;

      // Use the next position.
      int nxt_taken = nxt_blank ^ 1;
      ndp[nxt_taken] = max(ndp[nxt_taken], dp[j] + weight);
    }
    dp = move(ndp);
  }

  cout << *max_element(dp.begin(), dp.end());
}