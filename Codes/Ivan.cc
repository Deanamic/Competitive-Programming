#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

inline int solve (ll a, ll b, int m) {
  if(a == 0) return (b == 1 || b == 0);
  ll n = (int) sqrt (m + .0) + 10;

  ll an = 1;
  for (int i=0; i<n; ++i)
    an = (an * a) % m;

  unordered_map<ll,int> vals;
  for (ll i=1, cur=1; i<=n; ++i) {
    if (!vals.count(cur)) vals[cur] = 1;
    cur = (cur * an) % m;
  }

  for (ll i=0, cur=b; i<=n; ++i) {
    if (vals[cur]) return 1;
    cur = (cur * a) % m;
  }
  return 0;
}

inline int Case() {
  ll n,a,b;
  cin >> n >> a >> b;
  ll g;
  while(a != 0 && (g = gcd(a,n)) != 1) {
    if(b == 1) return cout << "YES" << '\n', 0;
    if(b%g != 0) return cout << "NO" << '\n', 0;
    b/=g;
    n/=g;
    ll inv, y;
    euclid(a/g, n, inv, y);
    inv = (inv%n + n)%n;
    b *= inv;
    b %= n;
  }

  if(solve(a,b,n)) cout << "YES" << '\n';
  else cout << "NO" << '\n';
  return 1;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    Case();
  }
}
