#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll oo = 0x3f3f3f3f3f3f3f3fLL;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define has(c, e) ((c).find(e) != (c).end())
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, h;
  cin >> n >> h;
  vector<long long> v(n);
  FOR(i, 0, n) cin >> v[i];
  int l = 0, r = n+1;
  while(l + 1 < r) {
    int m = (l + r)/2;
    auto aux = v;
    aux.resize(m);
    sort(all(aux));
    reverse(all(aux));
    ll curh = 0;
    for(int i = 0; i < m; ++i) {
      if(i % 2 == 0) {
        curh += aux[i];
      }
    }
    if(curh <= h) l = m;
    else r = m;
  }
  cout << l << endl;
  return 0;
}
