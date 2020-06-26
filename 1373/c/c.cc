#include <iostream>
#include <set>

using namespace std;
typedef long long ll;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    ll ans = s.size();
    int curr = 0;
    set<int> vis;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '+')
        curr++;
      else
        curr--;
      if (curr < 0 && !vis.count(curr)) {
        ans += i + 1;
        vis.insert(curr);
      }
    }
    cout << ans << endl;
  }
}