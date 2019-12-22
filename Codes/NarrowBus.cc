#include <bits/stdc++.h>
using namespace std;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);
uniform_int_distribution<int> distribution(0,1000000);

struct Node {
  int prior, key;
  int imp;
  Node *l, *r;
  Node() {}
  Node(int p, int k) : prior(p), key(k), (1), l(NULL), r(NULL) {}
};


inline int getCnt(Node* cur) {
  return cur ? cur -> cnt : 0;
}

void Update(Node* cur) {
  if(!cur) return;
  cur->cnt = 1 + getCnt(cur->l) + getCnt(cur->r);
}

Node* Merge(Node* N1, Node* N2) {
  if(!N1) return N2;
  if(!N2) return N1;
  if(N1->prior >= N2->prior) {
    N1->r = Merge(N1->r, N2);
    Update(N1);
    return N1;
  }
  N2 -> l = Merge(N1, N2->l);
  Update(N2);
  return N2;
}

pair<Node*,Node*> Split(Node* cur, int val) {
  if(!cur) return {NULL, NULL};
  if(cur->key >= val) {
    auto p = Split(cur->l, val);
    cur->l = p.second;
    Update(cur);
    return {p.first, cur};
  }
  auto p = Split(cur->r, val);
  cur->r = p.first;
  Update(cur);
  return {cur, p.second};
}

Node* Erase(Node* cur, int val) {
  if(cur->key == val) {
    cur = Merge(cur->l, cur->r);
    Update(cur);
    return cur;
  }
  if(cur->key > val) {
    cur->l = Erase(cur->l, val);
    Update(cur);
    return cur;
  }
  else {
    cur->r = Erase(cur->r, val);
    Update(cur);
    return cur;
  }
}

int main() {
  int n;
  cin >> n;
  Node* Root = NULL;
  int cnt = 0;
  for(int i = 0; i < n; ++i) {
    int rnd = distribution(generator);
    char c;
    cin >> c;
    if(c == 'F') {
      Node* N = new Node(rnd, ++cnt);
      Root = Merge(N, Root);
    }
    if(c == 'B') {
      Node* N = new Node(rnd, ++cnt);
      Root = Merge(Root, N);
    }
    if(c == 'O') {
      int x;
      cin >> x;
      auto p = Split(Root, x);
      p.second = Erase(p.second, x);
      cout << min(getCnt(p.first), getCnt(p.second)) << '\n';
      Root = Merge(p.second, p.first);
    }
  }
}
