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

inline bool in(int a, int b, int c) {
  return a >= b && a <= c;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x[3];
  int n, m, q;
  cin >> x[0] >> x[1] >> x[2] >> n >> m >> q;
  int g[3][2], b[3][2];
  memset(g, -1, sizeof(g));
  memset(b, -1, sizeof(b));

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < 3; ++j) {
      int a;
      cin >> a;
      if(g[i][0] == -1) g[i][0] = a;
      if(g[i][1] == -1) g[i][1] = a;
      g[i][0] = min(g[i][0],a);
      g[i][0] = max(g[i][0],a);
    }
  }

  for(int i = 0; i < m; ++i) {
    int a,bb, c;
    cin >> a >> bb >> c;
    if(in(a,g[0][0], g[0][1]) && in(bb,g[1][0], g[1][1]) && in(c,g[2][0], g[2][1])) {
      return cout << "INCORRECT" << endl, 0;
    }
    if(in(a,g[0][0], g[0][1]) && in(bb,g[1][0], g[1][1])) {
      if(c < g[2][0]) {
        if(b[2][0] == -1) b[2][0] = c;
        b[2][0] = max(c, b[2][0]);
      }
      if(c > g[2][1]) {
        if(b[2][1] == -1) b[2][1] = c;
        b[2][1] = max(c, b[2][1]);
      }
    }

    if(in(c,g[2][0], g[2][1]) && in(bb,g[1][0], g[1][1])) {
      if(a < g[0][0]) {
        if(b[0][0] == -1) b[0][0] = a;
        b[0][0] = max(c, b[0][0]);
      }
      if(a > g[0][1]) {
        if(b[0][1] == -1) b[0][1] = a;
        b[0][1] = min(c, b[0][1]);
      }
    }

    if(in(a,g[0][0], g[0][1]) && in(c,g[2][0], g[2][1])) {
      if(b < g[1][0]) {
        if(b[1][0] == -1) b[1][0] = bb;
        b[1][0] = max(c, b[1][0]);
      }
      if(b > g[1][1]) {
        if(b[1][1] == -1) b[1][1] = bb;
        b[1][1] = max(c, b[1][1]);
      }
    }
  }
  cout << "CORRECT" << endl;
  while(k--) {
    int a, bb, c;
    cin >> a >> bb >> c;
    if(in(a,g[0][0], g[0][1]) && in(bb,g[1][0], g[1][1]) && in(c,g[2][0], g[2][1])) {
      cout << "OPEN" << endl, 0;
    }

    else {


    }
  }
  return 0;
}
