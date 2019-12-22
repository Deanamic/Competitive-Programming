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

int v[200010];
int vis[200010];
void dfs(int u) {
  vis[u] = 1;
  if(!vis[v[u]]) dfs(v[u]);
}

int solve(int n) {
  for(int i = 0; i < n; ++i) {
    cin >> v[i];
    --v[i];
  }
  int ans = n;
  memset(vis, 0, sizeof(int)*n);
  for(int i = 0; i < n; ++i) {
    if(!vis[i]) dfs(i), --ans;
  }
  cout << ans << endl;
  return 0;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	//cin.exceptions(cin.failbit);
  int n;
  while(cin >> n) solve(n);
	return 0;
}
