#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;

int X = 0;
#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define has(c, e) ((c).find(e) != (c).end())
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()
#define pb push_back
#define N 400005
#define DEBUG(X) cerr << X++ << endl;

int sz[N];
vector<int> dominators(const vector<vector<int>> &g, int r) {
	int n = g.size();
	vector<int> ord, rank(n, n), prev(n, n), anc(n, n), idom(n, n), semi(n), low(n);
	vector<vector<int>> g_rev(n), dom(n);
	function<void(int)> dfs = [&](int u) {
		rank[u] = ord.size();
		ord.emplace_back(u);
		for (int v : g[u]){
			g_rev[v].emplace_back(u);
			if (rank[v] < n) continue;
			prev[v] = u;
			dfs(v);
		}
	};
	dfs(r);
	for (int i = 0; i < n; ++i) semi[i] = low[i] = i;
	function<int(int)> eval = [&](int v) {
		if (anc[v] < n && anc[anc[v]] < n)
		{
			int x = eval(anc[v]);
			if (rank[semi[low[v]]] > rank[semi[x]]) low[v] = x;
			anc[v] = anc[anc[v]];
		}
		return low[v];
	};
  FORD(i, 1, ord.size()) {
		int w = ord[i];
		for (int v : g_rev[w]) {
			int u = eval(v);
        	if (rank[semi[w]] > rank[semi[u]]) semi[w] = semi[u];
		}
		dom[semi[w]].emplace_back(w);
		anc[w] = prev[w];
		for (int v : dom[prev[w]]) {
			int u = eval(v);
			idom[v] = (rank[prev[w]] > rank[semi[u]] ? u : prev[w]);
		}
		dom[prev[w]].clear();
	}
  FOR(i, 1, ord.size()) {
		int w = ord[i];
		if (idom[w] != semi[w]) idom[w] = idom[idom[w]];
	}
  FOR(u, 0, n) if (idom[u] >= n) idom[u] = -1;
	return idom;
}

struct edge {
  int id, u, v;
  ll w;
};

int dfsz(int u,int p, int n, vector<vector<int>>& adj) {
  sz[u] = (u < n ? 1 : 0);
  for(auto v : adj[u]) {
      sz[u] += dfsz(v, u, n, adj);
  }
  return sz[u];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<edge> E;
  vector<vector<int>> adj(n);
  FOR(i, 0, m) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    adj[u].push_back(i);
    adj[v].push_back(i);
    E.push_back({i,u,v,w});
  }

  vector<ll> d(n,oo);
  d[0] = 0;
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
  for(pq.push({d[0],0}); pq.size();) {
    auto cur = pq.top();
    pq.pop();
    if(cur.first == d[cur.second]) {
      int u = cur.second;
      ll curw = d[u];
      for(int i : adj[u]) {
        int v = E[i].u ^ u ^ E[i].v;
        if(d[v] > curw + E[i].w) {
          d[v] = (curw + E[i].w);
          pq.push({d[v], v});
        }
      }
    }
  }
  vector<vector<int>> dadj(n+m);
  vector<int> ans(m,0);
  FOR(i, 0, m) {
    edge e = E[i];
    if(d[e.u] + e.w == d[e.v]) {
      dadj[e.u].push_back(n+e.id);
      dadj[n+e.id].push_back(e.v);
    }
    if(d[e.v] + e.w == d[e.u]) {
      dadj[e.v].push_back(n+e.id);
      dadj[n+e.id].push_back(e.u);
    }
  }
  auto dom = dominators(dadj, 0);
  vector<vector<int>> dTree(n+m);
  FOR(i, 0, m+n) {
    cout << dom[i] << endl;
    if(dom[i] != -1 && dom[i] != n + m) {
      dTree[dom[i]].push_back(i);
    }
  }
  memset(sz, 0, sizeof(sz));
  dfsz(0,0,n,dTree);
  FOR(i, n, n+m) cout << sz[i] << ' ';
  cout << endl;
	return 0;
}
