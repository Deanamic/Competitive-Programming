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

int dp[5000][1500] = {};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q, m;
  cin >> n >> m >> q;
  int w[n];
  FOR(i, 0, n) cin >> w[i];

  int cnt[5000] = {};
  FOR(i, 0, m) {
    string s;
    cin >> s;
    int x = 0;
    for(int j = 0; j < n; ++j) {
      x <<= 1;
      if(s[j] == '1') ++x;
    }
    cnt[x]++;
  }
  for(int i = 0; i < (1<<12); ++i) {
    for(int j = 0; j < (1<<12); ++j) {
      int val = 0;
      int it = n-1;
      int auxi = i, auxj = j;
      while(it >= 0) {
        if((i&1) == (j&1)) val += w[it];
        i/=2;j/=2;
        it--;
      }
      i = auxi; j = auxj;
      dp[i][val] += cnt[j];
    }
    for(int j = 1; j < 1500; ++j) dp[i][j] += dp[i][j-1];
  }
  FOR(i, 0, q) {
    string s; int k;
    cin >> s >> k;
    int x = 0;
    for(int j = 0; j < n; ++j) {
      x <<= 1;
      if(s[j] == '1') ++x;
    }
    cout << dp[x][k] << '\n';
  }
	return 0;
}
