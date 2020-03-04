#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <vector>
#define M_PI 3.14159265358979323846264338327950288

using namespace std;

class Solution {
  vector<complex<double>> fft(vector<complex<double>> &a, complex<double> w) {
    int len = a.size();
    if (len == 1)
      return a;

    vector<complex<double>> even, odd;
    for (int i = 0; i < len / 2; ++i) {
      even.emplace_back(a[2 * i]);
      odd.emplace_back(a[2 * i + 1]);
    }
    vector<complex<double>> f_even = fft(even, w * w), f_odd = fft(odd, w * w);
    complex<double> x(1);
    vector<complex<double>> values(len, 0);
    for (int i = 0; i < len / 2; ++i) {
      values[i] = f_even[i] + x * f_odd[i];
      values[i + len / 2] = f_even[i] - x * f_odd[i];
      x *= w;
    }

    return values;
  }

  vector<int> mul(vector<int> &a, vector<int> &b) {
    int len = a.size() + b.size() - 1;
    int n = 1;
    while ((1 << n) < len)
      n++;
    len = 1 << n;
    for (int i = 0; i < len - a.size(); ++i)
      a.emplace_back(0);
    for (int i = 0; i < len - b.size(); ++i)
      b.emplace_back(0);
    vector<complex<double>> a_comp, b_comp;
    for (int i : a)
      a_comp.emplace_back(complex<double>(i));
    for (int i : b)
      b_comp.emplace_back(complex<double>(i));
    complex<double> w = exp(complex<double>(2 * M_PI / len) * 1i);
    vector<complex<double>> a_val = fft(a_comp, w), b_val = fft(b_comp, w);
    for (int i = 0; i < a_val.size(); ++i)
      a_val[i] *= b_val[i];
    vector<complex<double>> c_val = fft(a_val, complex<double>(1) / w);
    vector<int> result;
    for (auto ci : c_val)
      result.emplace_back(int(ci.real() / len));
    return result;
  }

public:
  void solve() {
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i)
      scanf("%d", &b[i]);
    vector<int> c = mul(a, b);
    for (int i = 0; i < c.size(); ++i)
      if (c[i] % p != 0) {
        printf("%d", i);
        return;
      }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}