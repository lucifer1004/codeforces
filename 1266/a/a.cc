#include <iostream>
#include <vector>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int sum = 0;
  int zeros = 0;
  int even = 0;
  for (const char &c : s) {
    sum += c - '0';
    if (c == '0') zeros++;
    if ((c != '0') && (c - '0') % 2 == 0) even++;
  }

  if (sum % 3 != 0 || zeros == 0 || (zeros == 1 && even == 0))
    cout << "cyan" << endl;
  else
    cout << "red" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}