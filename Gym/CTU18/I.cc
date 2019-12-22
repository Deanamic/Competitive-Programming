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

int solve(ll n) {
  map<int,ll> m1,m2;
  map<pair<int,int>,ll> m;
  for(int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    m[{x,y}]++;
    m1[x+y]++;
    m2[x-y]++;
  }
  ll pos = n*n;
  ll cnt = 0;
  for(auto i : m1) cnt += i.second * (i.second);
  for(auto i : m2) cnt += i.second * (i.second);
  for(auto i : m) cnt -= 2*i.second * (i.second);
  //cout << cnt << ' ' << pos << endl;
  cout << (long double)cnt/(long double)pos << endl;
  return 0;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	//cin.exceptions(cin.failbit);
  cout.setf(ios::fixed);
  cout.precision(10);
  int n;
  while(cin >> n) solve(n);
	return 0;
}
