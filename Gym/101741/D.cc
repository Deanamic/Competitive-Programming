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
int cnt = 0;

int solve(int n) {
  vector<pair<ll,ll>> aux,v;
  FOR(i, 0, n) {
    ll x, y;
    cin >> x >> y;
    y <<= 1;
    aux.push_back({x,y});
  }
  ll mn = -100000;
  FORD(i, 0, n) if(aux[i].second > mn) v.push_back(aux[i]), mn = aux[i].second;
  reverse(v.begin(),v.end());
  n = sz(v);
  ll dp[n];
  dp[0] = v[0].first + v[0].second;
  FOR(i, 1, n) {
    int l = 0, r = i;
    while(l + 1 < r) {
      int k = (l+r)/2;
      if(max(v[i].first,dp[k]) + v[k+1].second > max((k ? dp[k-1] : 0),v[i].first) + v[k].second) l = k;
      else r = k;
    }
    dp[i] = v[i].first + v[0].second;
    FOR(k, l-30, l+30) {
      if(k >= 0 && k < i) dp[i] = min(dp[i], max(v[i].first, dp[k]) + v[k+1].second);
    }
  }
  cout << dp[n-1] << '\n';
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  while(cin >> n) solve(n);
	return 0;
}
