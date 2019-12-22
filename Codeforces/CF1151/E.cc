#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()
#define debug(x) cerr << #x << ": " << x << endl;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  vi h;
  int l = -1;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    if(x != l) h.push_back(x);
    l = x;
  }
  ll ans = h[0]*(n-h[0]+1);
  FOR(i, 1, sz(h)) {
    if(h[i-1] > h[i]) {
      ans += (h[i-1]-1-h[i]+1)*(h[i]-1+1);
    }
    else {
      ans += (h[i]-h[i-1])*(n-h[i]+1);
    }
  }
  cout << ans << endl;
}
