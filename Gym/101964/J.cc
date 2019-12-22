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

struct edge {
  int u, v;
  ll t, r;
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n);
  vector<vector<int> > djk(n);
  vector<edge> E;
  for(int i = 0; i < m; ++i) {
    int x, y, w1, w2;
    cin >> x >> y >> w1 >> w2;
    --x, --y;
    adj[x].push_back(E.size());
    djk[y].push_back(E.size());
    E.push_back({x, y, w1, w2});
  }
  int nt, nr;
  cin >> nt;
  vector<ll> rt(nt), rst(nt);
  FOR(i, 0, nt) {
    cin >> rt[i] >> rst[i];
    --rt[i];
  }
  cin >> nr;
  vector<ll> dnxt(n,-1);
  vector<ll> rr(nr);
  FOR(i, 0, nr) {
    cin >> rr[i];
    --rr[i];
    dnxt[E[rr[i]].u] = E[rr[i]].v;
  }
  vector<ll> rleft(n,oo), tleft(n,oo);
  ll tm = 0;
  FORD(i, 0, nr) {
    tm += E[rr[i]].r;
    rleft[E[rr[i]].u] = tm;
  }

  tm = 0;
  FORD(i, 0, nt) {
    tm += E[rt[i]].t;
    tleft[E[rt[i]].u] = tm;
  }


  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pqt, pqr;
  vector<ll> dt(n,oo), dr(n,oo), dcheat(n,oo);
  for(pqt.push({dt[n-1] = 0, n-1}); pqt.size(); pqt.pop()) {
    auto cur = pqt.top();
    if(dt[cur.second] == cur.first) {
      for(int i : djk[cur.second]) {
        edge e = E[i];
        if(dt[e.u] > dt[e.v] + e.t) {
          dt[e.u] = dt[e.v] + e.t;
          pqt.push({dt[e.u], e.u});
        }
      }
    }
  }
  for(pqr.push({dr[n-1]= 0, n-1}); pqr.size(); pqr.pop()) {
    auto cur = pqr.top();
    if(dr[cur.second] == cur.first) {
      for(int i : djk[cur.second]) {
        edge e = E[i];
        if(dr[e.u] > dr[e.v] + e.r) {
          dr[e.u] = dr[e.v] + e.r;
          pqr.push({dr[e.u], e.u});
        }
      }
    }
  }
  FOR(i, 0, n) {
    for(int j : adj[i]) {
      if(E[j].v != dnxt[i]) dcheat[i] = min(dcheat[i], E[j].r + dr[E[j].v]);
    }
  }
  ll TT = 0, TR = 0;
  int posT = 0, posR = 0;
  ll itT = 0, itR = 0;
  int rest = 0;
  set<int> ans;
  while(posT != n-1 && posR != n-1) {
    if(TR + dcheat[posR] <= TT + tleft[posT] && dcheat[posR] < rleft[posR]) ans.insert(posR);
    if(TT <= TR) {
      if(!rest) {
        posT = E[rt[itT]].v;
        TT += E[rt[itT]].t;
        rest = 1;
      }
      else rest = 0, TT += rst[itT++];
    }
    else {
      posR = E[rr[itR]].v;
      TR += E[rr[itR++]].r;
    }

  }
  cout << ans.size() << '\n';
  for(auto i : ans) cout << i + 1 << ' ';
  cout << '\n';
	return 0;
}
