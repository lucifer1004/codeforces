#include <string>
#include <vector>

std::vector<int> kmp(const std::string &s, const std::string &t) {
  int n = t.size();
  std::vector<int> ans;
  std::string a = t + "#" + s;
  std::vector<int> pi(a.size());
  for (int i = 1; i < a.size(); ++i) {
    int j = pi[i - 1];
    while (j != 0 && a[i] != a[j])
      j = pi[j - 1];
    pi[i] = a[i] == a[j] ? j + 1 : 0;
    if (pi[i] == n)
      ans.emplace_back(i - 2 * n);
  }
  return ans;
}