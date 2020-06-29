#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node {
  string name;
  Node *parent = nullptr;
  vector<Node *> children;
  Node(string &name) : name(name){};
};

class Corporate {
  Node *root = nullptr;

  void dfs(Node *u, map<string, int> &cnt, int &tot) {
    tot += cnt[u->name]++;
    for (Node *child : u->children)
      dfs(child, cnt, tot);
    cnt[u->name]--;
  }

public:
  Corporate(string &s) {
    string name;
    Node *p = nullptr;
    for (char c : s) {
      if (c >= 'A' && c <= 'Z')
        name.push_back(c);
      if (c == ':') {
        if (!root) {
          root = new Node(name);
          p = root;
        } else {
          Node *child = new Node(name);
          child->parent = p;
          p->children.emplace_back(child);
          p = child;
        }
        name.clear();
      }
      if (c == '.') {
        if (name.empty())
          p = p->parent;
        else {
          if (!root) {
            root = new Node(name);
          } else {
            Node *child = new Node(name);
            child->parent = p;
            p->children.emplace_back(child);
          }
          name.clear();
        }
      }
      if (c == ',')
        continue;
    }
  }

  int count() {
    int ans = 0;
    map<string, int> cnt;
    dfs(root, cnt, ans);
    return ans;
  }
};

int main() {
  string s;
  cin >> s;
  Corporate c(s);
  cout << c.count();
}