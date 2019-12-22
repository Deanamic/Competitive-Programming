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
  int a,b,c,n;
  cin >> a >> b >> c >> n;
  if(c > min(a,b)) return cout << -1 << endl, 0;
  if(max(a,max(b,c)) > n) return cout << -1 << endl , 0;
  int ans = n - (a + b - c);
  cout << (ans > 0 ? ans : -1) << endl;
	return 0;
}
