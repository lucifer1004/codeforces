#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  int t;
  cin >> t;
  vector<vector<string>> f = {{"00", "00", "00"},
                              {"01", "10", "11"},
                              {"10", "11", "01"},
                              {"11", "01", "10"}};
  while (t--) {
    ll n;
    cin >> n;
    ll g = (n - 1) / 3; // 属于第几个三元组
    ll k = (n - 1) % 3; // 是这个三元组中的第几个数
    vector<ll> a;
    while (g) {
      a.emplace_back((g - 1) % 4);
      g = (g - 1) / 4;
    }
    vector<string> ans = {"01", "10", "11"};
    reverse(a.begin(), a.end());
    for (int i : a)
      for (int j = 0; j < 3; ++j)
        ans[j] += f[i][j];
    cout << bitset<64>(ans[k]).to_ullong() << endl;
  }
}