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
  ll n;
  cin >> n;
  vector<ll> v(n);
  FOR(i, 0, n) cin >> v[i];
  sort(all(v));
  int q;
  cin >> q;
  vector<ll> d(n, 0);
  FOR(i, 1, n) d[i] = v[i] - v[i-1];
  sort(all(d));
  // for(auto i : d) cout << i << ' ';
  // cout << endl;
  vector<ll> p(n,0);
  p[0] = d[0];
  FOR(i, 1, n) p[i] = p[i-1] + d[i];
  while(q--) {
    ll a, b;
    cin >> a >> b;
    ll sz = b - a + 1;
    ll l = 0, r = n;
    while(l + 1 < r) {
      ll m = (l + r)/2;
      if(d[m] < sz) l = m;
      else r = m;
    }
    // cout << l << endl;
    // cout << ans << endl;
    // cout << r << endl;
    // cout << p[r] << endl;
    cout << (n-l)*sz + p[l] << '\n';
  }
  return 0;
}
