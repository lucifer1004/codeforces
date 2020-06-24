#include <iostream>
#include <vector>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int l = 0;
    while (l < n && s[l] == '0')
      l++;
    int r = n - 1;
    while (r >= 0 && s[r] == '1')
      r--;
    if (l == n || r == -1 || l == r + 1)
      cout << s << endl;
    else
      cout << s.substr(0, l) + "0" + s.substr(r + 1, n - r - 1) << endl;
  }
}