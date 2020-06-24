#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  int balance = 0;
  for (char c : s)
    balance += c == '1';
  for (char c : t)
    balance -= c == '1';
  if (balance != 0) {
    cout << -1;
    return 0;
  }
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0' && t[i] == '1')
      q.push(0);
    if (s[i] == '1' && t[i] == '0')
      q.push(1);
  }
  while (q.front() == 1) {
    q.pop();
    q.push(1);
  }
  vector<int> sum(2), curr(2);
  while (!q.empty()) {
    int f = q.front();
    q.pop();
    if (curr[1 - f] > 0)
      curr[1 - f]--;
    else
      sum[f] = max(sum[f], ++curr[f]);
  }
  cout << sum[0] + sum[1];
}