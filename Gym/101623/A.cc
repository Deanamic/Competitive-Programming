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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<int> v;
  int n;
  cin >> n;
  int lst;
  cin >> lst;
  FOR(i, 1, n) {
    int x;
    cin >> x;
    if(x != lst) {
      v.push_back(lst);
      lst = x;
    }
  }
  v.push_back(lst);
  n = sz(v);
  set<int> s;
  FOR(i, 0, n) s.insert(v[i]);
  map<int,int> val;
  int cnt = 0;
  for(auto i : s) val[i] = cnt++;
  FOR(i, 0, n) v[i] = val[v[i]];
  vector<vector<int>> cmp(cnt);
  vector<int> ssz(cnt);
  FOR(i, 0, n - 1) {
    if(cmp[v[i]].size() < 3) {
      if(v[i+1] == v[i] + 1) cmp[v[i]].push_back(i);
    }
    ssz[v[i]]++;
  }
  ssz[v[n-1]]++;
  int dp[cnt][4];
  memset(dp, 0, sizeof(dp));
  FOR(i, 0, sz(cmp[0])) dp[0][i] = 1;
  FOR(i, 1, cnt) {
    FOR(j, 0, sz(cmp[i])) {
      int curans = dp[i-1][3] + 1;
      FOR(k, 0, sz(cmp[i-1])) {
        if(cmp[i-1][k] + 1 != cmp[i][j] || ssz[i] == 1) curans = max(curans, dp[i-1][k] + 1);
      }
      curans = max(dp[i-1][3], curans);
      dp[i][j] = curans;
    }
    FOR(j, 0, sz(cmp[i-1])) dp[i][3] = max(dp[i][3], dp[i-1][j]);
    dp[i][3] = max(dp[i-1][3], dp[i][3]);
  }
  cout << n - 1 - dp[cnt-1][3] << endl;
  return 0;
}
