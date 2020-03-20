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