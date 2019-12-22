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

void solve(int n, char c) {
  if(c == 'R') {
    cout << n << endl;
  }
  if(c == 'K') {
    if(n == 1) cout << 1 << endl;
    if(n >= 2) cout << 4 << endl;
  }
  if(c == 'N') {
    if(n == 1) cout << 1 << endl;
    if(n == 2) cout << 1 << endl;
    if(n >= 3) cout << 2 << endl;
  }
  if(c == 'B') {
    cout << n << endl;
  }
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	//cin.exceptions(cin.failbit);
  int n;
  char c;
  while(cin >> n >> c) solve(n, c);
	return 0;
}
