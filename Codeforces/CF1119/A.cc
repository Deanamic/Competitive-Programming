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
  int n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  int ans1 = 0, ans2 = 0;
  FOR(i, 0, n) if(a[i] != a[0]) ans1 = i;
  reverse(a.begin(), a.end());
  FOR(i, 0, n) if(a[i] != a[0]) ans2 = i;
  cout << max(ans1, ans2) << endl;
  return 0;
}
