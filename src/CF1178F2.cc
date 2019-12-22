#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()
#define debug(x) cerr << #x << ": " << x << endl;

const ll MOD = 998244353;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  int c[n];
  vector<int> app[n];
  FOR(i, 0, n) {
    cin >> c[i];
    app[--c[i]].push_back(i);
  }
  ll ways = 1;
  FORD(i, 0, n) {
    int l = app[i][0];
    int r = app[i].back();
    ll lways = 1, rways = 1;
    while(l >= 0 && c[l] > i) {
      ++lways;
      --l;
    }
    while(r < n && c[r] > i) {
      ++rways;
      ++r;
    }
    ways *= ((lways)*(rways))%MOD;
    ways %= MOD;
  }
  cout << ways << endl;
}
