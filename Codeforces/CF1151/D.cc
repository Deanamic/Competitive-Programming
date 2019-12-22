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
  vi a(n), b(n);
  FOR(i, 0, n) cin >> a[i] >> b[i];
  vi id(n);
  FOR(i, 0, n) id[i] = i;
  sort(id.begin(), id.end(), [&](auto i1, auto i2) {
                               return a[i1] - b[i1] > a[i2] - b[i2];
                             });
  ll cur = 0;
  FOR(i, 0, n) {
    cur += i*a[id[i]] + b[id[i]] * (n-i-1);
  }
  cout << cur << endl;
}
