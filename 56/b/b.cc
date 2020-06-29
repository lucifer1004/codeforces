#include <iostream>
#include <vector>

using namespace std;
void fail() {
  cout << "0 0" << endl;
  exit(0);
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  int idx = 0;
  while (idx < n && a[idx] == idx + 1)
    idx++;
  if (idx == n)
    fail();
  int sum = idx + a[idx];
  vector<int> v = {idx};
  for (int i = idx + 1; i < n; ++i) {
    if (a[i] + i == sum)
      v.emplace_back(i);
    else if (a[i] == i + 1)
      continue;
    else
      fail();
  }
  for (int i = 0; i < (int)v.size() - 1; ++i)
    if (v[i] + 1 != v[i + 1])
      fail();
  cout << v.front() + 1 << " " << v.back() + 1 << endl;
}