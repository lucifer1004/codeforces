#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_set<int> in, once;
  int days = 0;
  vector<int> day{0};
  for (int i = 1; i <= n; ++i) {
    int p;
    cin >> p;
    bool enter = p > 0;
    if (p < 0)
      p = -p;
    if (enter) {
      if (once.find(p) != once.end()) {
        cout << -1;
        return 0;
      }
      once.insert(p);
      in.insert(p);
    } else {
      if (in.find(p) == in.end()) {
        cout << -1;
        return 0;
      }
      in.erase(p);
      if (in.empty()) {
        once.clear();
        days++;
        day.emplace_back(i);
      }
    }
  }
  if (!in.empty()) {
    cout << -1;
    return 0;
  }
  cout << days << endl;
  for (int i = 1; i <= days; ++i)
    cout << day[i] - day[i - 1] << " ";
  return 0;
}