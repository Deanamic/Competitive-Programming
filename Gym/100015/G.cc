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


struct query{
  int i, j, z;
  char c;
};

void solve(int n, int m, int q) {
  int x, y, z;
  char mander, c;
  vector<vector<int>> adj(n+m,vector<int>(n+m,0x3f3f3f3f));
  vector<query> Q;
  FOR(i, 0, q) {
    cin >> x >> y >> c >> mander >> z;
    --x, --y;
    y += n;
    Q.push_back({x, y, z, c});
  }

  for(auto& q1 : Q) {
    for(auto& q2 : Q) {
      int dif = -(q1.z - q2.z);
      if(q1.i == q2.i) {
        if(q1.c == '>' && q2.c != '>') {
          adj[q1.j][q2.j] = min(adj[q1.j][q2.j],dif);
        }
        if(q1.c != '>' && q2.c == '>') {
          adj[q2.j][q1.j] = min(adj[q2.j][q1.j],-dif);
        }
      }
      if(q1.j == q2.j) {
        if(q1.c == '>' && q2.c != '>') {
          adj[q1.i][q2.i] = min(adj[q1.i][q2.i],dif);
        }
        if(q1.c != '>' && q2.c == '>') {
          adj[q2.i][q1.i] = min(adj[q2.i][q1.i],-dif);
        }
      }
    }
  }

  vector<int> d(n+m, 0x3f3f3f3f);
  d[0] = 0;
  FOR(I, 0, n+m) {
    FOR(u, 0, n+m) {
      FOR(v, 0, n+m) {
        d[v] = min(d[v], d[u] + adj[u][v]);
      }
    }
  }

  FOR(u, 0, n+m) {
    FOR(v, 0, n+m) {
      if(d[v] > d[u] + adj[u][v]) {
        cout << "Impossible" << endl;
        return;
      }
    }
  }
  cout << "Possible" << endl;

}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, q;
  while(cin >> n >> m >> q) {
    if(n == 0) return 0;
    solve(n, m, q);
  }
	return 0;
}
