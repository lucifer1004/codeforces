#include <iostream>
#include <map>
#include <vector>

using namespace std;
int main() {
  int n;
  map<int, int> cnt;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  if (cnt.begin()->second <= n / 2)
    cout << "Alice";
  else
    cout << "Bob";
}