#include <iostream>
#include <string>
#include <vector>

std::vector<int> manacher(const std::string &s) {
  std::string t = "&";
  for (char c : s) {
    t.push_back('$');
    t.push_back(c);
  }
  t += "$#";
  std::vector<int> a(t.size());
  for (int i = 0, l = 0, r = -1; i < t.size(); ++i) {
    int j = (i > r) ? 1 : std::min(a[l + r - i], r - i + 1);
    while (i >= j && i + j < t.size() && t[i - j] == t[i + j])
      j++;
    a[i] = j--;
    if (i + j > r) {
      l = i - j;
      r = i + j;
    }
  }
  return a;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    int n = s.size();
    int l = 0, r = n - 1;
    while (l < r) {
      if (s[l] == s[r]) {
        l++;
        r--;
      } else
        break;
    }
    if (l >= r) {
      std::cout << s << std::endl;
      continue;
    }
    std::string ans = s.substr(0, l) + s.substr(n - l, l);
    std::vector<int> a = manacher(s);
    int best = l * 2, maxbi = -1, maxlen = -1, maxleft = -1;
    for (int i = 2; i <= 2 * n; ++i) {
      int len = a[i] - 1;
      int left = i / 2 - len / 2 - (i & 1 ? 0 : 1);
      int right = n - left - len;
      int bi = std::min(left, right);
      if (bi > l)
        continue;
      int newlen = len + bi * 2;
      if (newlen > best) {
        best = newlen;
        maxlen = len;
        maxleft = left;
        maxbi = bi;
      }
    }
    if (maxbi != -1)
      ans = s.substr(0, maxbi) + s.substr(maxleft, maxlen) +
            s.substr(n - maxbi, maxbi);
    std::cout << ans << std::endl;
  }
}