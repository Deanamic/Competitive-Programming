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

typedef vector<int> VI;
typedef vector<VI> VVI;
const ll INF = 1000000000000000000LL;

#define VEI(w,e) ((E[e].u == w) ? E[e].v : E[e].u)
#define CAP(w,e) ((E[e].u == w) ? E[e].cap[0] - E[e].flow : E[e].cap[1] + E[e].flow)
#define ADD(w,e,f) E[e].flow += ((E[e].u == w) ? (f) : (-(f)))

struct Edge { int u, v; ll cap[2], flow; };

VI d, act;

bool bfs(int s, int t, VVI& adj, vector<Edge>& E) {
  queue<int> Q;
  d = VI(adj.size(), -1);
  d[t] = 0; Q.push(t);
  while (not Q.empty()) {
    int u = Q.front(); Q.pop();
    for (int i = 0; i < int(adj[u].size()); ++i) {
      int e = adj[u][i], v = VEI(u, e);
      if (CAP(v, e) > 0 and d[v] == -1) {
        d[v] = d[u] + 1;
        Q.push(v);
      }
    }
  }
  return d[s] >= 0;
}

ll dfs(int u,int t,ll bot,VVI& adj,vector<Edge>& E) {
  if (u == t) return bot;
  for (; act[u] < int(adj[u].size()); ++act[u]) {
    int e = adj[u][act[u]];
    if (CAP(u, e) > 0 and d[u] == d[VEI(u, e)] + 1) {
      ll inc=dfs(VEI(u,e),t,min(bot,CAP(u,e)),adj,E);
      if (inc) {
        ADD(u, e, inc);
        return inc;
      }
    }
  }
  return 0;
}

ll maxflow(int s, int t, VVI& adj, vector<Edge>& E) {
  for (int i=0; i<int(E.size()); ++i) E[i].flow = 0;
  ll flow = 0, bot;
  while (bfs(s, t, adj, E)) {
    act = VI(adj.size(), 0);
    while ((bot = dfs(s,t,INF, adj, E))) flow += bot;
  }
  return flow;
}

void addEdge(int u, int v, VVI& adj, vector<Edge>& E, ll cap){
	Edge e; e.u = u; e.v = v;
	e.cap[0] = cap; e.cap[1] = 0;
	e.flow = 0;
	adj[u].push_back(E.size());
	adj[v].push_back(E.size());
	E.push_back(e);
}


inline void addEdge(int x, int y, ll c, vector<vi>& adj, vector <Edge> & E){
  Edge e;
  e.flow = 0;
  e.u = x; e.v = y;
  e.cap[0] = c; e.cap[1] = 0; //change if undirected edge
  adj[x].push_back(E.size());
  adj[y].push_back(E.size());
  E.push_back(e);
}


int m, n, k;
bool vis[4096];
ll ff(int u, int t, ll bot, vector<vi>& adj,vector<Edge>& E) {
  vis[u] = 1;
  if (u == t) return bot;
  for (int i = 0; i < int(adj[u].size()); ++i) {
    int e = adj[u][i];
    if (CAP(u, e) > 0 and !vis[VEI(u,e)]) {
      ll inc=ff(VEI(u,e),t,min(bot,CAP(u,e)),adj,E);
      if (inc) {
        ADD(u, e, inc);
        return inc;
      }
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k;
  vector<vector<int>> adj(n+m+2);
  const int S = n + m, T = n + m + 1;
  vector<Edge> E;
  FOR(i, 0, n) {
    addEdge(S, i, 1, adj, E);
  }
  FOR(i, 0, m) {
    addEdge(n + i, T, 1, adj, E);
  }
  FOR(i, 0, k) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    addEdge(x, n + y, 1, adj, E);
  }
  ll ans = 0, curans = 0;

  curans = maxflow(S,T,adj,E);

  FOR(i, 0, n){
    vector<Edge> CE = E;
    CE[i].cap[0] = 3;
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    cnt += ff(S,T,oo,adj,CE);
    memset(vis, 0, sizeof(vis));
    cnt += ff(S,T,oo,adj,CE);
    ans = max(curans + cnt, ans);
  }
  cout << max(curans,ans) << endl;
	return 0;
}
