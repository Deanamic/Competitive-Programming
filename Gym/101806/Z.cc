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
  int v[n];
  FOR(i, 0, n) cin >> v[i];
  int ans = 2;
  FOR(j, 0, 2) {
    FOR(k, 0, n) {
      int curans = 1;
      FOR(i, k, n-1) {
        if((j + i)%2) {
          if(v[i] > v[i+1]) {
            ++curans;
          }
          else break;
        }
        else {
          if(v[i] < v[i+1]) {
            ++curans;
          }
          else break;
        }
      }
      ans = max(ans, curans);
    }
  }
  cout << ans << endl;
	return 0;
}
