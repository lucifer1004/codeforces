#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;
typedef unsigned int uint;
ull query(vector<uint> &a) {
  cout << "? " << a.size() << " ";
  for (int i : a)
    cout << i << " ";
  cout << endl;
  ull result;
  cin >> result;
  return result;
}
int main() {
  int n;
  cin >> n;
  vector<uint> composites(n);
  vector<vector<uint>> queries(13);
  int idx = 0;
  for (uint i = (1u << 6u) - 1; idx < n; ++i) {
    vector<uint> set_bits;
    for (uint j = 0; j < 13; ++j)
      if (i & (1u << j))
        set_bits.emplace_back(j);
    if (set_bits.size() == 6) {
      for (uint j : set_bits) {
        composites[idx] += 1u << j;
        queries[j].emplace_back(idx + 1);
      }
      idx++;
    }
  }
  vector<ull> results(13);
  for (int i = 0; i < 13; ++i)
    if (!queries[i].empty())
      results[i] = query(queries[i]);
  vector<ull> ans(n);
  for (int i = 0; i < n; ++i)
    for (uint j = 0; j < 13; ++j)
      if (!(composites[i] & (1u << j)))
        ans[i] |= results[j];
  cout << "! ";
  for (ull i : ans)
    cout << i << " ";
  cout << endl;
}