#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()
#define debug(x) cerr << #x << ": " << x << endl;

int dp[1024][1024];
const long long MOD = 998244353;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  int a[n];
  FOR(i, 0, n) cin >> a[i];
  sort(a, a+n);
  long long ans = 0;
  FOR(i, 1, (a[n-1]-a[0])/(m-1) + 1) {
    FOR(k, 1, m) {
      ll prefsum = 0;
      int lp = 0;
      FOR(j, 0, n) {
        dp[j][0] = 1;
        FOR(l, lp, j) {
          if(a[j] - a[l] < i) break;
          prefsum += dp[l][k-1];
          prefsum %= MOD;
          lp++;
        }
        dp[j][k] = prefsum;
        dp[j][k] %= MOD;
      }
    }
    FOR(j, m-1, n) {
      ans += dp[j][m-1];
      ans %= MOD;
    }
  }
  cout << ans << endl;
}
