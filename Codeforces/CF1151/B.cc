#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()
#define debug(x) cerr << #x << ": " << x << endl;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vi> v(n, vi(m));
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      cin >> v[i][j];
    }
  }
  vi dif(n,-1);
  int g = -1;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if(v[i][j] != v[i][0]) {
        dif[i] = j + 1;
        g = i;
        break;
      }
    }
  }
  int cur1 = 0;
  FOR(i, 0, n) cur1 ^= v[i][0];
  if(cur1) {
    cout << "TAK" << endl;
    FOR(i, 0, n) cout << 1 << ' ';
    cout << endl;
  }
  else if(g != -1) {
    cout << "TAK" << endl;
    FOR(i, 0, n) cout << (i == g ? dif[i] : 1) << ' ';
    cout << endl;
  }
  else cout << "NIE" << endl;
}
