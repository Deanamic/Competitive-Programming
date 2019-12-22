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

int dp[110][4] = {};

inline int val(int i, int j) {
  if(i < 0) return 0;
  return dp[i][j];
}

inline int allval(int i) {
  if(i < 0) return 0;
  int cur = 0;
  for(int j = 0; j < 4; ++j) cur = max(cur, dp[i][j]);
  return cur;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s[2];
  cin >> s[0] >> s[1];

  FOR(i, 1, s[0].size()) {
    //put XX
    //    X.
    if(s[0][i-1] == '0' && s[1][i-1] == '0' && s[0][i] == '0') {
      dp[i][1] = max(val(i,1), max(val(i-1,0) , allval(i-2)) + 1);
    }
    //put XX
    //    .X
    if(s[0][i-1] == '0' && s[0][i] == '0' && s[1][i] == '0') {
      dp[i][3] = max(dp[i][3], max(dp[i-1][0],max(dp[i-1][2], allval(i-2))) + 1);
    }
    //put X.
    //    XX
    if(s[0][i-1] == '0' && s[1][i-1] == '0' && s[1][i] == '0') {
      dp[i][2] = max(val(i,1), max(val(i-1,0) , allval(i-2)) + 1);
    }
    //put .X
    //    XX
    if(s[1][i-1] == '0' && s[0][i] == '0' && s[1][i] == '0') {
      dp[i][3] = max(dp[i][3], max(dp[i-1][0],max(dp[i-1][1], allval(i-2))) + 1);
    }
    //put nothing
    int curmask = (s[0][i] == 'X') + 2*(s[1][i] == 'X');
    dp[i][curmask] = max(dp[i][curmask],allval(i-1));
    //FOR(j, 0, 4) cout << dp[i][j] << ' ';
    //cout << endl;
  }
  cout << allval((int)s[0].size() - 1) << endl;
	return 0;
}
