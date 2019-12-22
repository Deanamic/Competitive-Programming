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

const int MOD = 1e9 + 7;

ll binpow(ll x, ll k) {
  ll ans = 1;
  while(k > 0) {
    if(k&1) {
      ans *= x;
      ans %= MOD;
    }
    x *= x;
    x %= MOD;
    k >>= 1;
  }
  return ans;
}

ll n, m, c;

ll f(ll x) {
  return binpow(c, x*n*n);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> c;
  ll ans = 0;
  FOR(i, 0, m) {
    ans += f(__gcd(i, (int)m));
    ans %= MOD;
  }
  ans *= binpow(m, 1e9 + 5);
  cout << ans%MOD << endl;
	return 0;
}
