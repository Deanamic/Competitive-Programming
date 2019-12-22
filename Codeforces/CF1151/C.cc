#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()
#define debug(x) cerr << #x << ": " << x << endl;

const ll MOD = 1e9 + 7;

pair<ll,ll> num(ll r) {
  pair<ll,ll> p = {0,0};
  int I = 0;
  int e = 0;
  ll cur = 0;
  while(cur + (1LL<<e) <= r) {
    ll x = (1LL<<e);
    if(!I) p.first += x;
    else p.second += x;
    I ^= 1;
    p.first %= MOD;
    p.second %= MOD;
    cur += (1LL<<e);
    e++;
  }
  if(!I) p.first += r - cur;
  else p.second += r - cur;
  // cout << p.first << ' ' << p.second << endl;
  p.first %= MOD;
  p.second %= MOD;
  return p;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll l, r;
  cin >> l >> r;
  --l;
  auto p1 = num(r);
  auto p2 = num(l);
  ll ans = p1.first * p1.first - p2.first*p2.first;
  ans %= MOD;
  ans -= p2.second * p2.second + p2.second;
  ans += p1.second * p1.second + p1.second;
  ans %= MOD;
  ans += MOD;
  ans %= MOD;
  cout << ans << endl;
}
