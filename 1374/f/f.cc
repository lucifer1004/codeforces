#include <cstdio>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

class Solution {
public:
  void solve() {
    int n;
    read(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      read(a[i]);
    vector<int> seq;

    for (int i = 0; i < n - 2; ++i) {
      int ma = INF, mi = -1;
      for (int j = i; j < n; ++j) {
        if (a[j] <= ma) {
          ma = a[j];
          mi = j;
        }
      }
      for (int j = mi; j > i;) {
        if (j - i >= 2) {
          int tmp = a[j - 2];
          a[j - 2] = a[j];
          a[j] = a[j - 1];
          a[j - 1] = tmp;
          seq.emplace_back(j - 1);
          j -= 2;
        } else if (a[j - 1] > a[j]) {
          int tmp = a[j - 1];
          a[j - 1] = a[j];
          a[j] = a[j + 1];
          a[j + 1] = tmp;
          seq.emplace_back(j);
          seq.emplace_back(j);
          j--;
        } else
          break;
      }
    }

    if (a[n - 2] > a[n - 1]) {
      // Last three is in the form of "1-2-1", we can shift once to
      // get the correct order.
      // There cannot be numbers equal to the last with index smaller
      // than n - 3, since in the last stage, we always chose the last
      // one when there are equal numbers.
      if (a[n - 1] == a[n - 3]) {
        seq.emplace_back(n - 2);
      } else {
        int i = n - 3;
        while (i > 0 && a[i] != a[i - 1])
          i--;
        if (i > 0) {
          // If there are two equal numbers in the front, we can leverage them
          // to reorder the last two, by first shifting the two numbers to the
          // end, reordering the last two, and then shifting them back.
          for (int j = i + 1; j <= n - 3; ++j)
            seq.emplace_back(j - 1);
          seq.emplace_back(n - 3);
          seq.emplace_back(n - 3);
          seq.emplace_back(n - 2);
          seq.emplace_back(n - 2);
          for (int j = n - 5; j >= i - 1; --j) {
            seq.emplace_back(j + 1);
            seq.emplace_back(j + 1);
          }
        } else {
          // Otherwise we have no answer.
          for (int i = 0; i < n - 1; ++i)
            if (a[i] > a[i + 1]) {
              printf("-1\n");
              return;
            }
        }
      }
    }

    printf("%d\n", (int)seq.size());
    for (int i : seq)
      printf("%d ", i);
    printf("\n");
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}