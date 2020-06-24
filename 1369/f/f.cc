#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ll;

bool win(ll s, ll e) {
  if (e & 1)
    return !(s & 1);
  if (s * 2 > e)
    return (e - s) % 2 == 1;
  if (s * 4 > e)
    return true;
  return win(s, e / 4);
}

bool lose(ll s, ll e) {
  if (s * 2 > e)
    return true;
  return win(s, e / 2);
}

int main() {
  int n;
  cin >> n;
  bool first = 1, second = 0;
  bool noop = false;
  for (int i = 0; i < n; ++i) {
    ll s, e;
    cin >> s >> e;
    if (noop)
      continue;
    if (!(first ^ second)) {
      noop = true;
      continue;
    }
    bool w = win(s, e), l = lose(s, e);
    if (second)
      w ^= 1, l ^= 1;
    first = l, second = w;
  }
  cout << second << " " << first;
}