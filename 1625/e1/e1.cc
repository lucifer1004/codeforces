#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define MAXN 300005

using namespace std;
using ll = long long;

template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

struct Node {
  int l, r, idx;
  ll score;
  Node *parent;
  vector<Node *> children;
  vector<ll> psum;

  Node(int l, int r) : l(l), r(r), idx(0), score(0), parent(nullptr) {}
};

int lp[MAXN]{}, rp[MAXN]{};
map<pair<int, int>, Node *> mp;

void dfs(Node *node) {
  mp[{node->l, node->r}] = node;
  int m = (int)node->children.size();
  if (m <= 1) {
    // For m >= 2, the whole node is counted in the end, not here.
    node->score = 1;
    lp[node->l] = node->r;
    rp[node->r] = node->l;
  }

  sort(node->children.begin(), node->children.end(),
       [&](Node *a, Node *b) { return a->l < b->l; });

  // Assign children's indices
  int idx = 0;
  for (auto child : node->children) {
    child->idx = idx++;
    dfs(child);
    node->score += child->score;
  }

  // Calculate prefix sum
  if (m >= 2) {
    node->psum = vector<ll>(m + 1);
    for (int i = 0; i < m; ++i)
      node->psum[i + 1] = node->psum[i] + node->children[i]->score;
  }

  node->score += 1LL * m * (m - 1) / 2;
}

int main() {
  int n, Q;
  read(n), read(Q);
  string s;
  cin >> s;

  unordered_map<int, Node *> left, right;
  unordered_set<Node *> dead;
  queue<Node *> que;
  for (int i = 0; i + 1 < n; ++i) {
    if (s[i] == '(' && s[i + 1] == ')') {
      Node *node = new Node(i, i + 1);
      left[i] = right[i + 1] = node;
      que.push(node);
    }
  }

  while (!que.empty()) {
    Node *node = que.front();
    que.pop();
    if (dead.count(node) || node->parent != nullptr) continue;
    int l = node->l, r = node->r;
    if (l >= 1 && r + 1 < n && s[l - 1] == '(' && s[r + 1] == ')') {
      // Case 1: ((*)) [l, r] => [l - 1, r + 1]
      Node *par = new Node(l - 1, r + 1);
      left[l - 1] = right[r + 1] = par;
      left.erase(l), right.erase(r);
      que.push(par);
      node->parent = par;
      par->children.push_back(node);
    } else if (l >= 1 && right.count(l - 1)) {
      // Case 2: (...)(*) [l, r] => [ll, r]
      Node *lnei = right[l - 1];
      if (lnei->children.size() >= 2 &&
          lnei->children.size() >= node->children.size()) {
        // Case 2.1: Left is larger
        left.erase(l), right[r] = lnei, right.erase(lnei->r), lnei->r = r;
        if (node->children.size() >= 2) {
          // Case 2.1.1: Merge
          for (auto child : node->children) {
            lnei->children.push_back(child);
            child->parent = lnei;
          }
          dead.insert(node);
        } else {
          // Case 2.1.2: Assign
          lnei->children.push_back(node);
          node->parent = lnei;
        }
        que.push(lnei);
      } else if (node->children.size() >= 2) {
        // Case 2.2: Current is larger
        left.erase(l), left[lnei->l] = node, right.erase(lnei->r),
                       node->l = lnei->l;
        if (lnei->children.size() >= 2) {
          // Case 2.2.1: Merge
          for (auto child : lnei->children) {
            node->children.push_back(child);
            child->parent = node;
          }
          dead.insert(lnei);
        } else {
          // Case 2.2.2: Assign
          node->children.push_back(lnei);
          lnei->parent = node;
        }
        que.push(node);
      } else {
        // Case 2.3: Create a parent node
        Node *par = new Node(lnei->l, r);
        left[lnei->l] = right[r] = par;
        left.erase(l), right.erase(lnei->r);
        que.push(par);
        par->children.push_back(node);
        par->children.push_back(lnei);
        node->parent = par, lnei->parent = par;
      }
    } else if (r + 1 < n && left.count(r + 1)) {
      // Case 3: (*)(...) [l, r] => [l, rr]
      Node *rnei = left[r + 1];
      if (rnei->children.size() >= 2 &&
          rnei->children.size() >= node->children.size()) {
        left.erase(rnei->l), left[l] = rnei, right.erase(r), rnei->l = l;
        if (node->children.size() >= 2) {
          for (auto child : node->children) {
            rnei->children.push_back(child);
            child->parent = rnei;
          }
          dead.insert(node);
        } else {
          rnei->children.push_back(node);
          node->parent = rnei;
        }
        que.push(rnei);
      } else if (node->children.size() >= 2) {
        left.erase(rnei->l), right[rnei->r] = node, right.erase(r),
                             node->r = rnei->r;
        if (rnei->children.size() >= 2) {
          for (auto child : rnei->children) {
            node->children.push_back(child);
            child->parent = node;
          }
          dead.insert(rnei);
        } else {
          node->children.push_back(rnei);
          rnei->parent = node;
        }
        que.push(node);
      } else {
        Node *par = new Node(l, rnei->r);
        left[l] = right[rnei->r] = par;
        left.erase(rnei->l), right.erase(r);
        que.push(par);
        par->children.push_back(node);
        par->children.push_back(rnei);
        node->parent = par, rnei->parent = par;
      }
    }
  }

  for (auto [l, node] : left) dfs(node);

  while (Q--) {
    int t, l, r;
    read(t), read(l), read(r);
    l--, r--;

    if (lp[l] == r) {
      printf("%lld\n", mp[{l, r}]->score);
    } else {
      int p = lp[l], q = rp[r];
      auto lnode = mp[{l, p}], rnode = mp[{q, r}];
      Node *par = lnode->parent;
      int lidx = lnode->idx, ridx = rnode->idx;
      int m = ridx - lidx + 1;
      printf("%lld\n", par->psum[rnode->idx + 1] - par->psum[lnode->idx] +
                           1LL * m * (m - 1) / 2);
    }
  }
}