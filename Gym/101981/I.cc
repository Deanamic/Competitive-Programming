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
#define VEI(w,e) (E[e].u ^ E[e].v ^ w)
#define CAP(w,e) ((E[e].u == w) ? E[e].cap[0] - E[e].flow : E[e].cap[1] + E[e].flow)
#define ADD(w,e,f) E[e].flow += ((E[e].u == w) ? (f) : (-(f)))

struct Edge{ int u, v; ll cap[2], flow; };
vi d, act;

ll bfs(int s, int t, vector<vi>& adj, vector<Edge>& E, ll lim) {
  queue<int> Q;
  d = vi(adj.size(), -1);
  d[t] = 0; Q.push(t);
  for (Q.push(t); Q.size() and d[s] == -1; Q.pop()) {
    int u = Q.front();
    FOR(i, 0, adj[u].size()) {
      int e = adj[u][i], v = VEI(u, e);
      if (CAP(v, e) >= lim and d[v] == -1) {
        d[v] = d[u] + 1;
        Q.push(v);
      }
    }
  }
  return (d[s] >= 0 ? lim : 0);
}

ll dfs(int u, int t, ll bot, vector<vi>& adj,vector<Edge>& E) {
  if (bot == 0) return 0;
  if (u == t) return bot;
  for (; act[u] < int(adj[u].size()); ++act[u]) {
    int e = adj[u][act[u]];
    if(d[u] == d[VEI(u, e)] + 1) {
      ll inc=dfs(VEI(u,e),t,min(bot,CAP(u,e)),adj,E);
      if (inc) {
        ADD(u, e, inc);
        return inc;
      }
    }
  }
  return 0;
}

ll maxflow(int s, int t, vector<vi>& adj, vector<Edge>& E, int F = 0) {
  ll flow = 0, bot;
  for(int lim = (1<<F); lim >= 1;) {
    if(!bfs(s,t,adj,E,lim)) {
      lim >>= 1;
      continue;
    }
    act = vi(adj.size(), 0);
    while (bot = dfs(s, t, oo, adj, E)) flow += bot;
  }
  return flow;
}

inline void addEdge(int x, int y, ll c, vector<vi>& adj, vector <Edge> & E){
  Edge e; e.u = x; e.v = y; e.flow = 0;
  e.cap[0] = c; e.cap[1] = 0; //change if undirected edge
  adj[x].push_back(E.size()); adj[y].push_back(E.size());
  E.push_back(e);
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  int S = n + m, S1 = n + m + 1, T = n + m + 2;
  vector<vector<int>> adj(n+m+3);
  vector<Edge> E;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    FOR(j, 0, x) {
      int y;
      cin >> y;
      --y;
      addEdge(i, y+n, 1, adj, E);
    }
  }
  FOR(i, 0, m) {
    addEdge(i+n, T,1,adj,E);
  }
  FOR(i, 0, n) {
    addEdge(S1, i, 1, adj, E);
    addEdge(S, i, 1, adj, E);
  }
  addEdge(S, S1, k, adj, E);
  cout << maxflow(S,T, adj, E) << endl;
	return 0;
}
