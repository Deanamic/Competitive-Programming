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

ll dp[1024];
ll dpl[1024];
const int MOD = 1e9 +7;
ll ch[2048][2048];

ll choose(int n, int k) {
  return ch[n][k];
}

ll get(int n);

ll getl(int n) {
  if(dpl[n] != -1) return dpl[n];
  dpl[n] = (2*getl(n-1)*(2*n - 1))%MOD;
  return dpl[n];
}

ll get(int n) {
  if(dp[n] != -1) {
    return dp[n];
  }
  dp[n] = 0;
  FOR(i, 1, n+1) {
    ll cur = 2*(getl(i-1) * getl(n-i))%MOD; //escoges cual pintas primero
    cur *= choose(2*(n - 1), 2*(i - 1)); //escoges el orden el cual pintas
    cur %= MOD;
    cur *= 2*n - 1; //escoges cuando insertas
    cur %= MOD;
    //cout << cur << endl;
    dp[n] += cur;
    dp[n] %= MOD;
  }
  return dp[n];
}

void solve(int n) {
  cout << get(n) << endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  memset(dp, -1, sizeof(dp));
  memset(dpl, -1, sizeof(dpl));
  ch[0][0] = 1;
  ch[1][0] = 1;
  ch[1][1] = 1;
  FOR(i, 2, 2040) {
    FOR(j, 0, i + 1) {
      ll cur = 0;
      if(j) cur += ch[i-1][j-1];
      if(j <= i - 1) cur += ch[i-1][j];
      ch[i][j] = cur%MOD;
    }
  }
  dp[0] = 1;
  dp[1] = 2;
  dpl[0] = 1;
  dpl[1] = 2;
  while(cin >> n) {
    if(n == 0) {
      return 0;
    }
    solve(n);
  }
	return 0;
}
