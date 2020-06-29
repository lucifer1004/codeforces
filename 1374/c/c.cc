#include <iostream>
#include <vector>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int bal = 0, ans = 0;
    for (char c : s) {
      if (c == '(')
        bal++;
      else
        bal--;
      if (bal < 0) {
        ans++;
        bal = 0;
      }
    }
    cout << ans << endl;
  }
}