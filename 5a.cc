#include <iostream>

using namespace std;

int main() {
  string line;
  int people = 0, messages = 0;
  while (getline(cin, line)) {
    if (line[0] == '+')
      people++;
    else if (line[0] == '-')
      people--;
    else {
      int i = 0;
      while (line[i] != ':') i++;
      int len = line.size() - i - 1;
      messages += people * len;
    }
  }
  cout << messages;
  return 0;
}