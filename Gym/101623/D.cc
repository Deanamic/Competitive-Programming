#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll oo = 0x3f3f3f3f3f3f3f3fLL;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define has(c, e) ((c).find(e) != (c).end())
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()

string cor = "correct";
string inc = "incorrect";

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  unordered_map<string, ll> mr, mw;
  unordered_map<string, string> trad;
  vector<string> v(n);
  FOR(i, 0, n) {
    cin >> v[i];
  }
  int Q;
  cin >> Q;
  while(Q--) {
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    trad[s1] = s2;
    if(s3[0] == 'i') mw[s1]++;
    else mr[s1]++;
  }
  ll tot = 1;
  ll r = 1;
  ll w = 1;
  FOR(i, 0, n) {
    tot *= (mr[v[i]] + mw[v[i]]);
    r *= mr[v[i]];
    w *= mw[v[i]];
  }
  if(tot == 1) {
    FOR(i, 0, n) cout << trad[v[i]] << ' ';
    cout << endl;
    if(r == 1) cout << cor << endl;
    else cout << inc << endl;
  }
  else cout << r << ' ' << cor << endl << tot - r << ' ' << inc << endl;
	return 0;
}
