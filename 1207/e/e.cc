#include <iostream>

int main() {
  std::cout << "? ";
  for (int i = 1; i <= 100; ++i)
    std::cout << i << " ";
  std::cout << std::endl;
  int left;
  std::cin >> left;
  std::cout << "? ";
  for (int i = 0; i < 100; ++i)
    std::cout << (i << 7) << " ";
  std::cout << std::endl;
  int right;
  std::cin >> right;
  int ans = (left & (127 << 7)) + (right & 127);
  std::cout << "! " << ans << std::endl;
}