#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
  double solve_equation(double a, double b, double c) {
    double delta = b * b - 4 * a * c;
    if (delta < 0) return -1;
    return (sqrt(delta) - b) / (2 * a);
  }

 public:
  void solve() {
    double a, v, l, d, w;
    cin >> a >> v >> l >> d >> w;
    w = min(v, w);

    // Stage 1
    double t1;
    double dw = 0.5 * w * w / a;

    // vm < w
    if (dw > d) {
      t1 = sqrt(2 * d / a);
      // Update the start speed of Stage 2.
      w = a * t1;
    } else {
      double vm = sqrt(w * w / 2 + a * d);
      if (vm > v) {
        // vm = v
        double first = 0.5 * v * v / a;
        double third = 0.5 * (v * v - w * w) / a;
        double second = d - first - third;
        t1 = (2 * v - w) / a + second / v;
      } else {
        // w < vm < v
        t1 = (2 * vm - w) / a;
      }
    }

    // Stage 2
    double t2;
    double vm = w + solve_equation(1, 2 * w, -2 * a * (l - d));
    if (vm > v) {
      double first = 0.5 * (v * v - w * w) / a;
      double second = l - d - first;
      t2 = (v - w) / a + second / v;
    } else {
      t2 = (vm - w) / a;
    }

    printf("%.12lf", t1 + t2);
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}