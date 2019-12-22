#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()
#define debug(x) cerr << #x << ": " << x << endl;

string WINNER[2] = {"cslnb", "sjfnb"};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; ++i) cin >> v[i];
    ll cnt = 0;
    sort(v.begin(), v.end());
    if(n > 1 && v[0] == v[1] && v[0] == 0) return cout << WINNER[0] << endl, 0;
    for(int i = 0; i < n-1; ++i) {
      if(v[i] == v[i+1]) {
        --v[i], cnt = 1;
        break;
      }
    }
    for(int i = 0; i < n; ++i) {
      cnt += v[i];
      if(i && v[i] == v[i-1]) {
        return cout << WINNER[0] << endl, 0;
      }
    }
    ll tot = ((n-1)*(n))/2;
    cout << WINNER[(tot-cnt)&1] << endl;
}
