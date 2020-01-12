#include <iostream>
#include <list>
#include <set>
#include <vector>

using namespace std;

class Chat {
  int cap, head, len;
  vector<int> cache;
  set<int> dict;

 public:
  Chat(int cap) {
    this->cap = cap;
    this->cache = vector<int>(cap, -1);
    this->head = 0;
    this->len = 0;
  }

  void add(int id) {
    if (dict.find(id) == dict.end()) {
      len++;
      head--;
      if (head < 0) head += cap;
      if (cache[head] != -1) dict.erase(cache[head]);
      cache[head] = id;
      dict.insert(id);
    }
  }

  void display() {
    int size = min(cap, len);
    cout << size << endl;
    for (int i = 0; i < size; ++i) cout << cache[(head + i) % cap] << " ";
    cout << endl;
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  Chat chat(k);
  for (int i = 0; i < n; ++i) {
    int id;
    scanf("%d", &id);
    chat.add(id);
  }
  chat.display();
  return 0;
}