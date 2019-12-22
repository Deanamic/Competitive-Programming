#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define FOR(i, a, b) for(ll i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define has(c, e) ((c).find(e) != (c).end())
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()


const int MOD = 1e9 + 7;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
  //Eratostenes
  int n = 100010;
  vector<int> sieve(n+1, -1);
  sieve[0] = sieve[1] = 0;
  for (int i = 2; i * i <= n; i++) {
    if (sieve[i] == -1) {
      for (int j = i * i; j <= n; j += i)
        sieve[j] = i;
    }
  }
  long long N, M, L, R;
  cin >> N >> M >> L >> R;
  long long ans = 0;
  FOR(i, 1, min(N,R+1)) {
    ll b;
    ll l = 0, r = M;
    while(l + 1 < r) {
      ll mid = (r+l)/2;
      if(mid * mid + i * i > R * R) r = mid;
      else l = mid;
    }
    b = l;
    ll a;
    l = 0, r = M-1;
    while(l+1 < r) {
      ll mid = (r+l)/2;
      if(mid * mid + i * i < L*L) l = mid;
      else r = mid;
    }
    a = max(1LL,r);
    if(i*i + b*b < L*L) continue;
    if(i*i + a*a > R*R) continue;
    if(b < a) continue;
    if(a == b) {
      if(__gcd(a,i) == 1) {
        ans += (N-i)*(M-a);
        ans %= MOD;
      }
    }
    else {
      set<ll> pr;
      int aux = (int)i;
      while(aux != 1) {
        if(sieve[aux] == -1) {
          pr.insert(aux);
          break;
        }
        else pr.insert(sieve[aux]);
        aux /= sieve[aux];
      }
      vector<ll> v;
      for(auto j : pr) v.push_back(j);
      ll cursum = 0;
      ll curcnt = 0;
      FOR(j, 1, 1<<(v.size())) {
        ll sign = (__builtin_popcount((int)j)&1 ? 1 : -1);
        ll curval = 1;
        for(int k = 0; k < (int)v.size(); ++k) {
          if((1<<k) & j) curval *= v[k];
        }

        ll l1 = (a+curval-1)/curval;
        ll l2 = (b/curval);
        //if(l1 > l2) continue;
        curcnt += (l2 - l1 + 1);
        cursum += sign * curval * ((l1 + l2)*(l2-l1+1))/2;
        curcnt %= MOD;
        cursum %= MOD;
      }
      ll curM = (M)*((b - a + 1) - curcnt);
      ll curC = ((a + b)*(b - a + 1))/2 - cursum;
      curM %= MOD;
      curC %= MOD;
      ans += (N - i)*(curM - curC);
      ans = ans%MOD;
    }
  }
  ans = (2LL*(ans+MOD))%MOD;
  if(L == 1) {
    ans += N*(M-1) + M*(N-1);
  }
  cout << ans%MOD << endl;
}
