#pragma GCC target ("avx,avx2")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()
#define debug(x) cerr << #x << ": " << x << endl;

int v[4096][4096];
struct minWindow{
  int n;
  deque<int> l,m;
  minWindow(int k): n(k){}

  void insert(int x, int p) {
    while(l.size() && x < l.back()) {
      l.pop_back();
      m.pop_back();
    }
    l.push_back(x);
    m.push_back(p);
  }

  int getMin(int p) {
    while(m.size() && p - *m.begin() >= n) {
      m.pop_front();
      l.pop_front();
    }
    return *l.begin();
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  ll g, x, y, z;
  cin >> g >> x >> y >> z;
  v[0][0] = g;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      v[i][j] = g;
      g = (g*x + y)%z;
    }
  }
  vector<minWindow> rowans(n, minWindow(b));
  FOR(i, 0, n) {
    FOR(j, 0, b-1) {
      rowans[i].insert(v[i][j], j);
    }
  }
  ll ans = 0;
  FOR(j, b-1, m) {
    minWindow curans(a);
    FOR(i, 0, n) {
      rowans[i].insert(v[i][j], j);
    }
    FOR(i, 0, a-1) curans.insert(rowans[i].getMin(j), i);
    FOR(i, a-1, n) {
      curans.insert(rowans[i].getMin(j), i);
      ans += curans.getMin(i);
    }
  }
  cout << ans << '\n';
}
