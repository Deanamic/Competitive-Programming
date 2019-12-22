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

string p = "RPS";
string w = "PSR";

int rec(ll n) {
  if(n < 3) {
    return cout << w[n] << endl, 0;
  }
  ll mult = 3;
  while(3*mult <= n) mult *= 3;
  if(n < mult) rec(n);
  else if(n < 2*mult) rec(((n%mult)+mult/3)%mult);
  else rec(((n%mult)+2*mult/3)%mult);
  return 0;
}

void solve(ll n) {
  rec(n);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  while(cin >> n) {
    if(n == 0) return 0;
    solve(n - 1);
  }
	return 0;
}
