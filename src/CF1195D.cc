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
  int n;
  cin >> n;
  int w[n][11];
  memset(w, 0, sizeof(w));
  int l[n];
  int cnt[25];
  memset(cnt, 0, sizeof(cnt));
  FOR(i, 0, n) {
    int x;
    cin >> x;
    int j = 0;
    while(x) {
      w[i][j++] = x%10;
      x /= 10;
    }
    l[i] = j;
    cnt[j]++;
  }
  ll ans = 0;
  ll bp[30];
  ll val = 1;
  FOR(i, 0, 30) {
    bp[i] = val;
    val *= 10;
    val %= MOD;
  }
  FOR(i, 0, n) {
    FOR(k, 0, 11) {
      //LEFT ARG
      {
        ll curans = 0;
        int it = 0;
        FOR(j, 0, k+l[i]) {
          if((j&1) || (j>>1) >= k) {
            curans += w[i][it++] * bp[j];
            curans %= MOD;
          }
        }
        ll mul = cnt[k];
        ans += curans*mul;
        ans %= MOD;
      }
      //RIGHT ARG
      {
        ll curans = 0;
        int it = 0;
        FOR(j, 0, k+l[i]) {
          if((j&1) == 0 || (j>>1) >= k) {
            curans += w[i][it++] * bp[j];
            curans %= MOD;
          }
        }
        ll mul = cnt[k];
        ans += curans*mul;
        ans %= MOD;
      }
    }
  }
  cout << ans << endl;
}
