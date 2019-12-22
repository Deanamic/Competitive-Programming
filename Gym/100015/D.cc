#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define has(c, e) ((c).find(e) != (c).end())
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()

vector<int> vis;
vector<int> result;
vector<vector<int> > adj;
const long double ONE = 1;
void Toposort(int u){
  vis[u] = 2;
  for(int i : adj[u]){
    if(vis[i] == 2) while(1) {};
    if(!vis[i]) Toposort(i);
  }
  vis[u] = 1;
  result.push_back(u);
}

void solve(int n, int m) {
  result.clear();
  vis = vector<int> (n,0);
  adj = vector<vector<int > >(n);
  vector<vector<long double> > wei(n);

  for(int i = 0; i < m; ++i) {
    int x, y;
    int w;
    cin >> x >> y >> w;
    adj[x].push_back(y);
    wei[x].push_back(w);
  }

  for(int i = 0; i < n; ++i) {
    if(!vis[i]) Toposort(i);
  }
  vector<vector<long double> > dp(n, vector<long double>(2));
  for(int u : result) {
    if(sz(adj[u]) == 0) dp[u][0] = 0;
    else {
      long double sumw = 0;
      for(long double ww : wei[u]) sumw += ww;
      for(long double& ww : wei[u]) ww /= sumw;
      long double curans = 0;
      FOR(i, 0, sz(adj[u])) {
        curans += (dp[adj[u][i]][0]) * wei[u][i];
      }
      curans += ONE;
      dp[u][0] = curans;
      dp[u][1] = 0;
      if(sz(adj[u]) > 1) {
        FOR(i, 0, sz(adj[u])) {
          dp[u][1] = max(dp[u][1], (curans - (ONE+dp[adj[u][i]][0])*wei[u][i])/(ONE-wei[u][i]));
        }
      }

      FOR(i, 0, sz(adj[u])) {
        dp[u][1] = max(dp[u][1], (curans + ((dp[adj[u][i]][1]-dp[adj[u][i]][0])*wei[u][i])));
      }
    }
  }
  cout << fixed << setprecision(10) << max(dp[0][1], dp[0][0]) << endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  while(cin >> n >> m) {
    if(n == 0) return 0;
    solve(n, m);
  }
	return 0;
}
