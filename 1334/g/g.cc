#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> p(27);
  for (int i = 1; i <= 26; ++i)
    cin >> p[i];
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  s = s + "#" + t;
  string ans;
  vector<int> pi(s.size());
  for (int i = 1; i <= n + m; ++i) {
    int j = pi[i - 1];
    while (j != 0 && s[i] != s[j] && s[i] != ('a' + p[s[j] - 'a' + 1] - 1))
      j = pi[j - 1];
    if (s[i] == s[j] || s[i] == ('a' + p[s[j] - 'a' + 1] - 1))
      pi[i] = j + 1;
    if (i >= n * 2)
      ans.push_back(pi[i] == n ? '1' : '0');
  }
  cout << ans;
}