#include <iostream>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a = 0, n = s.size();
    for (char c : s)
      a += c == '0';
    int ans = min(a, n - a);
    cout << (ans % 2 == 1 ? "DA" : "NET") << endl;
  }
}