    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef vector<int> vi;

    #define FOR(i, a, b) for(int i = (a); i < int(b); i++)
    #define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
    #define sz(c) int((c).size())
    #define all(c) c.begin(), c.end()
    #define debug(x) cerr << #x << ": " << x << endl;

    struct edge {
      int u, v, w;
      int Xor() const {
        return u^v;
      }
    };

    vector<int> in;
    vector<edge> E;
    vector<vector<int>> adj;
    vector<vector<int>> par;
    int cnt = 0;

    int dfs(int u, int p, int orig) {
      par[u].push_back(orig);
      in[u] = cnt++;
      int l = u;
      for(int i : adj[u]) {
        int v = u^E[i].u^E[i].v;
        if(p != v) {
          l = dfs(v, u, orig);
          if(sz(par[u]) < 3) par[u].push_back(l);
        }
      }
      return l;
    }

    int main() {
      ios::sync_with_stdio(0); cin.tie(0);
      int n;
      cin >> n;
      if(n == 2) {
        int u, v, w;
        cin >> u >> v >> w;
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << u << ' ' << v << ' ' << w << endl;
        return 0;
      }
      in = vi(n,0);
      E.resize(n-1);
      adj.resize(n);
      par.resize(n);
      FOR(i, 0, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back(i);
        adj[v].push_back(i);
        E[i] = {u,v,w};
      }
      FOR(i, 0, n) if(sz(adj[i]) == 2) return cout << "NO" << endl, 0;
      cout << "YES" << endl;
      cout << 6*(n-1) << endl;
      FOR(i, 0, n) {
        if(sz(adj[i]) == 1) {
          dfs(i,i,i);
          break;
        }
      }
      for(edge e : E) {
        int u = e.u;
        int v = e.v;
        if(in[u] < in[v]) swap(u,v);
        if(sz(adj[v]) == 1) swap(u, v);
        if(sz(adj[u]) == 1) {
          vector<int> to;
          for(int j : par[v]) if(j != u) to.push_back(j);
          cout << u+1 << ' ' << to[0]+1 << ' ' << e.w/2 << '\n';
          cout << u+1 << ' ' << to[1]+1 << ' ' << e.w/2 << '\n';
          cout << to[0]+1 << ' ' << to[1]+1 << ' ' << -e.w/2 << '\n';
          cout << u+1 << ' ' << to[0]+1 << ' ' << 0 << '\n';
          cout << u+1 << ' ' << to[1]+1 << ' ' << 0 << '\n';
          cout << to[0]+1 << ' ' << to[1]+1 << ' ' << 0 << '\n';
        } else {
          cout << par[u][0]+1 << ' ' << par[u][1]+1 << ' ' << e.w/2 << '\n';
          cout << par[u][0]+1 << ' ' << par[u][2]+1 << ' ' << e.w/2 << '\n';
          cout << par[u][1]+1 << ' ' << par[u][2]+1 << ' ' << -e.w/2 << '\n';
          cout << par[v][0]+1 << ' ' << par[v][1]+1 << ' ' << -e.w/2 << '\n';
          cout << par[v][0]+1 << ' ' << par[v][2]+1 << ' ' << -e.w/2 << '\n';
          cout << par[v][1]+1 << ' ' << par[v][2]+1 << ' ' << e.w/2 << '\n';
        }
      }
    }
