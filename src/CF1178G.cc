#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define FOR(i, a, b) for (int i = (a); i < int(b); i++)
#define FORD(i, a, b) for (int i = (b)-1; i >= int(a); i--)
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()
#define debug(x) cerr << #x << ": " << x << endl;

const ll MAXN = 200005;
int tin[MAXN], tout[MAXN];
vector<int> adj[MAXN];
ll a[MAXN],b[MAXN];
ll suma[MAXN], sumb[MAXN];
vector<int> dfsorder;
int curT = 0;
const int grpSize = 200;

struct Line {
  ll m, n, d;
  ll eval(ll x) {
    return m*x + n;
  }
};

struct LineContainer {
  int idx;
  int n;
  int sz;
  ll inf = LLONG_MAX;
  vector<int> sortOrder;
  vector<ll> sumB;
  vector<Line> V;
  LineContainer(){}

  void init(vector<ll> B) {
    n = sz(B);
    sumB = B;
    V.resize(n);
    sortOrder.resize(n);
    vector<pair<ll,int>> w;
    for(int i = 0; i < n; ++i) {
      w.push_back({sumB[i], i});
    }
    sort(w.begin(), w.end());
    for(int i = 0; i < n; ++i) {
      sortOrder[i] = w[i].second;
    }
  }

  bool dominate(Line &l) {
    if(sz == 0) {
      l.d = -inf;
      return false;
    }
    l.d = (V[sz-1].n - l.n)/(l.m - V[sz-1].m);
    return l.d <= V[sz-1].d;
  }

  void insert(Line l) {
    if(sz && V[sz-1].m == l.m && V[sz-1].n >= l.n) return;
    if(sz && V[sz-1].m == l.m && V[sz-1].n < l.n) --sz;
    while(dominate(l)) --sz;
    V[sz++] = l;
  }

  void build(vector<ll>& A) {
    sz = 0; idx = 0;
    for(int i = 0; i < n; ++i) {
      int pos = sortOrder[i];
      ll a = sumB[pos];
      ll b = sumB[pos]*A[pos];
      insert({a, b, 0});
    }
  }

  ll query(ll x) {
    while(idx + 1 < sz && V[idx+1].d <= x) ++idx;
    return V[idx].eval(x);
  }
};

void dfs(int u, ll sum1 = 0, ll sum2 = 0) {
  tin[u] = curT++;
  dfsorder.push_back(u);
  sum1 += a[u]; sum2 += b[u];
  suma[u] = sum1; sumb[u] = abs(sum2);
  for (auto v : adj[u]) dfs(v, sum1, sum2);
  tout[u] = curT;
  sum1 -= a[u]; sum2 -= b[u];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  int numGroups = (n + grpSize - 1)/grpSize;
  for (int i = 1; i < n; ++i) {
    int x; cin >> x; --x;
    adj[x].push_back(i);
  }
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  dfs(0);
  vector<LineContainer> topHull(numGroups), botHull(numGroups);
  vector<ll> curC(numGroups, 0);

  for (int i = 0; i < numGroups; ++i) {
    vector<ll> va,vb;
    for(int j = 0; j < grpSize && i*grpSize+j < n; ++j) {
      int curPos = dfsorder[i*grpSize + j];
      va.push_back(suma[curPos]);
      vb.push_back(abs(sumb[curPos]));
    }
    topHull[i].init(vb);
    topHull[i].build(va);
    for(auto &z : vb) z *= -1LL;
    botHull[i].init(vb);
    botHull[i].build(va);
  }
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      ll v,x;
      cin >> v >> x;
      --v;
      int l = tin[v], r = tout[v]-1;
      int grpl = l/grpSize, grpr = r/grpSize;
      for (int i = grpl + 1;  i < grpr; ++i) {
        curC[i] += x;
      }

      for (int i = l; i <= r; ++i) {
        if(i/grpSize != l/grpSize) break;
        int u = dfsorder[i];
        suma[u] += x;
      }
      vector<ll> va;
      for (int i = 0; i < grpSize; ++i) {
        int curPos = grpl*grpSize + i;
        if(curPos >= n) break;
        curPos = dfsorder[curPos];
        suma[curPos] += curC[grpl];
        va.push_back(suma[curPos]);
      }
      topHull[grpl].build(va);
      botHull[grpl].build(va);

      curC[grpl] = 0;

      if(grpl == grpr) continue;

      for (int i = r; i >= l; --i) {
        if(i/grpSize != r/grpSize) break;
        int u = dfsorder[i];
        suma[u] += x;
      }
      va.resize(0);
      for (int i = 0; i < grpSize; ++i) {
        int curPos = grpr*grpSize + i;
        if(curPos >= n) break;
        curPos = dfsorder[curPos];
        suma[curPos] += curC[grpr];
        va.push_back(suma[curPos]);
      }
      topHull[grpr].build(va);
      botHull[grpr].build(va);
      curC[grpr] = 0;
    }
    else {
      int v;
      cin >> v; --v;
      int l = tin[v], r = tout[v]-1;
      int grpl = l/grpSize, grpr = r/grpSize;
      ll mx = -1;
      for (int i = grpl + 1;  i < grpr; ++ i) {
        mx = max(mx, abs(topHull[i].query(curC[i])));
        mx = max(mx, abs(botHull[i].query(curC[i])));
      }
      for (int i = l; i < min(min((grpl+1)*grpSize,n), r+1); ++i) {
        int u = dfsorder[i];
        mx = max(mx, abs((suma[u]+curC[grpl]) * sumb[u]));
      }
      for (int i = r; i >= max(l, grpSize*grpr); --i) {
        int u = dfsorder[i];
        mx = max(mx, abs((suma[u]+curC[grpr]) * sumb[u]));
      }
      cout << mx << '\n';
    }
  }
}
