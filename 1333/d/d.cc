#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int sum = 0, l = 0;
  vector<int> left;
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (c == 'L') {
      sum += i;
      l++;
      left.emplace_back(i);
    }
  }
  int target = l * (l - 1) / 2;
  int max_move = sum - target;
  if (k > max_move) {
    cout << -1;
    exit(0);
  }
  vector<vector<int>> moves;
  while (sum != target) {
    vector<int> m;
    for (int i = left.size() - 1; i >= 0; --i) {
      if (left[i] != i && (i == 0 || left[i - 1] < left[i] - 1)) {
        m.emplace_back(left[i]);
        left[i]--;
        sum--;
      }
    }
    moves.emplace_back(m);
  }
  int p = moves.size();
  if (k < p) {
    cout << -1;
    exit(0);
  }
  string ans;
  for (int i = 0; i < p; ++i) {
    int idx = 0;
    while (idx < moves[i].size() && k > p - i) {
      ans += "1 " + to_string(moves[i][idx]) + "\n";
      idx++;
      k--;
    }
    if (idx < moves[i].size()) {
      ans += to_string(moves[i].size() - idx) + " ";
      for (int j = idx; j < moves[i].size(); ++j)
        ans += to_string(moves[i][j]) + " ";
      ans += "\n";
      k--;
    }
  }
  cout << ans;
}