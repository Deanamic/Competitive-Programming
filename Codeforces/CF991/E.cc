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

ll ans = 0;
int v[10] = {};
int c[21][21] = {};
ll mult(vi& cur) {
  ll val = 1;
  ll sum = cur[1];
  FOR(i,2,10) {
    val*= c[sum+cur[i]][cur[i]];
    sum += cur[i];
    //cout << val << ' ';
    //if(i == 9) cout << endl << sum << ' ' << cur[i] << ' ' << c[sum][cur[i]] << endl;
  }
  return val;
}
void calc(vi& cur) {
  int z = cur[0];
  int cnt = 0;
  for(auto i : cur) cnt += i;
  cnt -= z;
  //for(auto i : cur) cout << i << ' ';
  //cout << endl;
  ans += mult(cur) * c[cnt-1+z][z];
}

void bt(int pos, vi& cur) {
  if(pos == 10) {
    calc(cur);
    return;
  }
  if(v[pos] == 0) {
    cur[pos] = 0;
    bt(pos + 1, cur);
    return;
  }

  for(int i = 1; i <= v[pos]; ++i) {
    cur[pos] = i;
    bt(pos+1,cur);
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  c[0][0] = 1;
  c[1][0] = 1;
  c[1][1] = 1;
  FOR(i, 2, 21) FOR(j, 0, i+1) {
    c[i][j] = c[i-1][j] + (j ? c[i-1][j-1] : 0);
  }
  for(char cc : s) {
    int x = cc-'0';
    v[x]++;
  }
  vector<int> cur(10);
  bt(0,cur);
  //cout << endl;
  cout << ans << endl;
	return 0;
}
