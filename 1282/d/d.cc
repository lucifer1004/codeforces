#include <iostream>

using namespace std;

int main() {
  int a, len, total = -1;
  cout << "a" << endl;
  cin >> a;
  if (a == 0) // "a"
    return 0;
  len = a + 1;
  string alla(len, 'a');
  if (len <= 300) {
    cout << alla << endl;
    cin >> total;
    if (total == 0) // "a...a"
      return 0;
  }
  if (len > 300 || total == len) { // "b...b"
    cout << string(len - 1, 'b') << endl;
    int result;
    cin >> result;
    return 0;
  }

  string ans(alla);
  int b = 0;
  for (int i = 0; i < len - 1; ++i) {
    string curr(alla);
    curr[i] = 'b';
    cout << curr << endl;
    int result;
    cin >> result;
    if (result == 0)
      return 0;
    if (result < total) {
      ans[i] = 'b';
      b++;
    }
  }
  if (b < total)
    ans[len - 1] = 'b';
  cout << ans << endl;
  int result;
  cin >> result;
}