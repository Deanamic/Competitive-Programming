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

ll n;

bool can(ll m) {
  ll cnt = 0;
  ll aux = n;
  while(aux) {
    cnt += min(m, aux);
    aux -= min(m, aux);
    aux -= aux/10;
  }
  return cnt >= (n+1)/2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  ll l = 0, r = n;
  while(l + 1 < r) {
    ll m = (l+r)>>1;
    if(can(m)) r = m;
    else l = m;
  }
  cout << r << endl;
	return 0;
}
