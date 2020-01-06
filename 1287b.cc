#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<string> card(n);
  unordered_set<string> s;
  unordered_map<char, int> dict;
  dict['S'] = 0;
  dict['E'] = 1;
  dict['T'] = 2;
  string st = "SET";

  for (int i = 0; i < n; ++i) {
    cin >> card[i];
    s.insert(card[i]);
  }

  ll ans = 0;
  for (int i = 0; i < n - 1; ++i)
    for (int j = i + 1; j < n; ++j) {
      string target(k, '*');
      for (int t = 0; t < k; ++t) {
        if (card[i][t] == card[j][t])
          target[t] = card[i][t];
        else
          target[t] = st[3 - dict[card[i][t]] - dict[card[j][t]]];
      }
      if (s.find(target) != s.end()) ans++;
    }

  cout << ans / 3;
}

int main() { solve(); }