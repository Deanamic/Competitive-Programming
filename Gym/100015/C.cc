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


struct SparseTable {
  vector<vector<int> > ST;
  vector<int > P;
  int N;
  int MAXLOG = 0;

  void build(int n, const vector<int>& V){
    N = n;
    while ((1 << MAXLOG) <= N) ++MAXLOG;
    ST = vector<vector<int> > (N, vector<int> (MAXLOG));
    P = vector<int> (N + 1);
    int LOG = 0;
    for (int i = 1; i < N + 1; ++i) {
      if(1 << (LOG+1) <= i) P[i] = ++LOG;
      else P[i] = LOG;
    }
    for (int i = 0; i < N; ++i) {
      ST[i][0] = i;
    }
    for (int j = 1; j < MAXLOG; ++j) {
      for (int i = 0; i + (1 << j) - 1 < N; ++i) {
        if (V[ST[i][j - 1]] < V[ST[i + (1 << (j - 1))][j - 1]])
          ST[i][j] = ST[i][j - 1];
        else
          ST[i][j] = ST[i + (1 << (j - 1))][j - 1];
      }
    }
  }

  int query(int l, int r, const vector<int>& V){
    int LOG = P[r - l + 1];
    if (V[ST[l][LOG]] < V[ST[r - (1 << LOG) + 1][LOG]])
      return ST[l][LOG];
    return ST[r - (1 << LOG) + 1][LOG];

  }
};

struct Tree {
  vector<vector<int> > adj;
  vector<vector<int> > wei;
  vector<int> d;
  int l1, l2, lw;
  int V, E;
  int LOG;
  vector<int> Eulerian_tour, RMQ_reduction, Ocurrence;
  SparseTable S;

  void Eulerian_dfs(int p, int u, int depth){
    if (Ocurrence[u] == -1) Ocurrence[u] = Eulerian_tour.size();
    Eulerian_tour.push_back(u);
    RMQ_reduction.push_back(depth);
    FOR(i, 0, sz(adj[u])) {
      int v = adj[u][i];
      if (v != p) {
        if(d[v] != -1) {
          l1 = u, l2 = v, lw = wei[u][i];
          continue;
        }
        d[v] = d[u] + wei[u][i];
        Eulerian_dfs(u, v, depth + 1);
        Eulerian_tour.push_back(u);
        RMQ_reduction.push_back(depth);
      }
    }
  }

  void build(int n){
    V = n;
    E = n - 1;
    adj.resize(V);
    wei.resize(V);
    d.resize(V,-1);
    Ocurrence = vector<int> (V, -1);
    for (int i = 0; i < V; ++i) {
      int x, y, w;
      cin >> x >> y >> w;
      adj[x].push_back(y);
      adj[y].push_back(x);
      wei[x].push_back(w);
      wei[y].push_back(w);
    }
    d[0] = 0;
    Eulerian_dfs(0, 0, 0);
    S.build(RMQ_reduction.size(), RMQ_reduction);
  }

  int query(int l, int r){
    int L = min(Ocurrence[l], Ocurrence[r]);
    int R = max(Ocurrence[l], Ocurrence[r]);
    return Eulerian_tour[S.query(L, R, RMQ_reduction)];
  }

  int dist(int x, int y) {
    int lca = query(x,y);
    int ans = d[x] + d[y] -2*d[lca];
    int lca1 = query(x,l1), lca2 = query(y,l2);
    ans = min(ans, d[x] + d[l1] - 2*d[lca1] + d[y] + d[l2] - 2*d[lca2] + lw);
    lca1 = query(x, l2), lca2 = query(y, l1);
    ans = min(ans, d[x] + d[l1] - 2*d[lca1] + d[y] + d[l2] - 2*d[lca2] + lw);
    return ans;
  }

};
void solve(int n) {
  Tree T;
  T.build(n);
  int Q;
  cin >> Q;
  while(Q--) {
    int x, y;
    cin >> x >> y;
    cout << T.dist(x,y) << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  while(cin >> n) {
    if(n == 0) return 0;
    solve(n);
  }
	return 0;
}
