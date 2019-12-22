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

int v[1024];

int solve(int n) {
  int ans = n;
  for(int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  if(n == 1) return cout << 1 << endl, 0;
  int d = v[n-1] - v[n-2];
  while(ans >= 2) {
    if(v[ans-1] - v[ans-2] == d) --ans;
    else return cout << ans << endl, 0;
  }
  cout << ans << endl;
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
	//cin.exceptions(cin.failbit);
  int n;
  while(cin >> n) solve(n);
	return 0;
}
