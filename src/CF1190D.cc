#include <bits/stdc++.h>
#include <bits/extc++.h> /** keep-include */

using namespace std;
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;

typedef long long ll;
typedef vector<int> vi;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()
#define debug(x) cerr << #x << ": " << x << endl;

struct point {
  point (int x,int y) : x(x), y(y) {}
  int x, y;
};

struct SegmentTree {
  vector <int> S;

  void build(int n) {
    S = vi(4*n,0);
  }

  void setValue(int id, int l, int r, int p) {
    if(l + 1 == r) {
      S[id] = 1;
      return;
    }
    int m = (l+r)>>1;
    if(p < m) setValue(id<<1, l, m, p);
    else setValue(id<<1|1, m, r, p);
    S[id] = S[id<<1] + S[id<<1|1];
  }

  ll get(int id, int l, int r, int x, int y) {
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return S[id];
    int m = (l+r)>>1;
    return get(id<<1,l,m,x,y) + get(id<<1|1,m,r,x,y);
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  set<int> s1,s2;
  vector<point> w;
  for(int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    s1.insert(x);
    s2.insert(y);
    w.emplace_back(x,y);
  }
  map<int,int> m1, m2;
  int val = 1;
  for(int i : s1) m1[i] = val++;
  int val2 = 1;
  for(int i : s2) m2[i] = val2++;

  for(auto& i : w) i.x = m1[i.x], i.y = m2[i.y];
  sort(w.begin(), w.end(), [](auto a, auto b) {
                             return (a.x == b.x) ? a.y < b.y : a.x < b.x;
                           });
  vector<vector<int>> v(val2);
  for(auto i : w) v[i.y].push_back(i.x);

  const int rgt = val + 10;
  SegmentTree S;
  S.build(rgt);
  ll ans = 0;
  for(int i = val2 - 1; i >= 0; --i) {
    for(int j : v[i]) S.setValue(1,0,rgt,j);
    int lft = 0;
    for(int j : v[i]) {
      ans += S.get(1, 0, rgt, lft, j + 1) * S.get(1, 0, rgt, j, rgt);
      lft = j + 1;
    }
  }
  cout << ans << endl;
}
