#include <bits/stdc++.h>
using namespace std;

/**
 * Author: Dean
 * License: CC0
 * Description: Builds an Ahocorasick Trie, with suffix links.
 * Time: O(n + m + z)
 * Status: Tested http://www.spoj.com/problems/STRMATCH/, https://codeforces.com/gym/101741/problem/K
 * Usage: This is an offline Algorithm, Pass the vector of patterns to Trie.init(v), find function returns the number of times each string appears
 */

typedef long long ll;
typedef vector<int> vi;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()
#define debug(x) cerr << #x << ": " << x << endl;

const int MaxM = 2000005;

struct Trie{
  static const int Alpha = 26;
  static const int first = 'A';
  int lst = 1;
  struct node{
    int nxt[Alpha] = {}, p = -1;
    char c;
    vi end; //if all patterns are different, can use flag instead
    int SuffixLink = -1;
    int cnt = 0;
  };
  vector<node> V;
  int num;
  stack<int> reversebfs;
  vector<int> ppos;
  inline int getval(char c) {
    return c - first;
  }
  void CreateSuffixLink() {
    queue<int> q;
    for(q.push(0); q.size(); q.pop()) {
      int pos = q.front();
      reversebfs.push(pos);
      if(!pos || !V[pos].p) V[pos].SuffixLink = 0;
      else {
        int val = getval(V[pos].c);
        int j = V[V[pos].p].SuffixLink;
        V[pos].SuffixLink = V[j].nxt[val];
      }
      for(int i = 0; i < Alpha; ++i) {
        if(V[pos].nxt[i]) q.push(V[pos].nxt[i]);
        else if(!pos || !V[pos].p)  V[pos].nxt[i] = V[0].nxt[i];
        else V[pos].nxt[i] = V[V[pos].SuffixLink].nxt[i];
      }
    }
  }

  void init(vector<string> &v) {
    V.resize(MaxM);
    ppos.resize(MaxM, 0);
    num = v.size();
    int id = 0;
    for(auto &s : v) {
      int pos = 0;
      for(char &c : s) {
        int val = getval(c);
        if(!V[pos].nxt[val]) {
          V[lst].p = pos; V[lst].c = c; V[pos].nxt[val] = lst++;
        }
        pos = V[pos].nxt[val];
      }
      V[pos].end.emplace_back(id++);
    }
    CreateSuffixLink();
  }

  void iterate(char C, int p, int i) {
    --p;
    int val = getval(C);
    if(p == -1) {
      ppos[i] = V[0].nxt[val];
    }
    else ppos[i] = V[ppos[p]].nxt[val];
    V[ppos[i]].cnt++; //We count the times we reach each node, and then do a reverse propagation
  }

  vi getAns() {
    vi ans(num, 0);
    for(;reversebfs.size();reversebfs.pop()) {
      int	x = reversebfs.top();
      for(int i : V[x].end) ans[i] += V[x].cnt;
      if(V[x].SuffixLink != -1) V[V[x].SuffixLink].cnt += V[x].cnt;
    }
    return ans;
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  vector<char> l(n);
  vi p(n);
  for(int i = 0; i < n; ++i) {
    cin >> l[i];
    cin >> p[i];
  }
  Trie T;
  vector<string> v(k);
  for(int i = 0; i < k; ++i) {
    cin >> v[i];
    reverse(v[i].begin(), v[i].end());
  }
  T.init(v);
  FOR(i, 0, n) {
    T.iterate(l[i], p[i], i);
  }
  auto ans = T.getAns();
  for(auto i : ans) cout << i << ' ';
  cout << endl;
}
