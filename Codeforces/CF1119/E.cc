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
  vi v(n);
  FOR(i, 0, n) cin >> v[i];
  ll pair = 0;
  ll ans = 0;
  FORD(i, 0, n) {
    pair += v[i]/2;
    v[i]&=1;
    if(v[i] == 1 && pair) ans++, pair--;
  }
  cout << ans + (2*pair)/3 << endl;
  return 0;
}
