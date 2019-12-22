#include <bits/stdc++.h>

#define rep(a,b,c) for(int a=(b); a<(c); ++a)
#define sz(c) ((c).size())


using namespace std;

typedef long long LL;
typedef long long ll;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;
typedef vector<ll> vl;


const ll mod2 = (119 << 23) + 1, root2 = 3; // = 998244353
const ll mod1 = (5 << 25) + 1, root1 = 3;

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

template <class Z> Z chinese(Z a, Z m, Z b, Z n) {
	Z x, y; euclid(m, n, x, y);
	Z ret = a * (y + m) % m * n + b * (x + n) % n * m;
	if (ret >= m * n) ret -= m * n;
	return ret;
}

ll modpow(ll a, ll e, ll mod) {
	if (e == 0) return 1;
	ll x = modpow(a * a % mod, e >> 1, mod);
	return e & 1 ? x * a % mod : x;
}

void ntt(ll* x, ll* temp, ll* roots, int N, int skip, ll mod) {
	if (N == 1) return;
	int n2 = N>>1;
	ntt(x     , temp, roots, n2, skip<<1, mod);
	ntt(x+skip, temp, roots, n2, skip<<1, mod);
	rep(i,0,N) temp[i] = x[i*skip];
	rep(i,0,n2) {
		ll s = temp[i<<1], t = temp[i<<1|1] * roots[skip*i];
		x[skip*i] = (s + t) % mod; x[skip*(i+n2)] = ((s - t) % mod + mod) %mod;
	}
}

void ntt(vl& x, ll mod, ll root,  bool inv = false) {
	ll e = modpow(root, (mod-1) / sz(x), mod);
	if (inv) e = modpow(e, mod-2, mod);
	vl roots(sz(x), 1), temp = roots;
	rep(i,1,sz(x)) roots[i] = roots[i-1] * e % mod;
	ntt(&x[0], &temp[0], &roots[0], sz(x), 1, mod);
}

vl conv(vl a, vl b, ll mod, ll root) {
	int s = sz(a) + sz(b) - 1; if (s <= 0) return {};
	int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
	if (s <= 200 && false) { // (factor 10 optimization for |a|,|b| = 10)
		vl c(s);
		rep(i,0,sz(a)) rep(j,0,sz(b)) {
			c[i + j] = (c[i + j] + a[i] * b[j]) % mod;
    }
		return c;
	}
	a.resize(n); ntt(a, mod, root);
	b.resize(n); ntt(b, mod, root);
	vl c(n); ll d =  modpow(n, mod-2, mod);
	rep(i,0,n) c[i] = a[i] * b[i] % mod * d % mod;
	ntt(c, mod, root, true); c.resize(s); return c;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<ll>a(n+1,0);
  a[0] = 1;
  int val = 0;
  ll curans = 0;
  ll cnt = 0;
  for(int i = 0; i < n; ++i) {
    int y;
    cin >> y;
    if(y < x) {
      val++;
      curans += (cnt*(cnt+1))/2;
      cnt = 0;
    }
    else {
      cnt++;
    }
    a[val]++;
  }
  curans += (cnt*(cnt+1))/2;
  auto b = a;
  reverse(b.begin(), b.end());
  auto ans = conv(a, b, mod1, root1);
  auto ans1 = conv(a, b, mod2, root2);
  cout << curans;
  for(int i = 1; i <= n; ++i) cout << ' ' << chinese(ans[i+n], mod1, ans1[i+n], mod2);
  cout << endl;
}
