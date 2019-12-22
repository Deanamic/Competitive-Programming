//ACCEPTED
//http://codeforces.com/contest/916/problem/E
//Tags: Tree, Lazy Segtree, Changing root

#include <bits/stdc++.h>
using namespace std;

long long vini[100010];
vector<int> adj[100010];
vector<int> child[100010];
int tin[100010], tout[100010];
int rev[100010];
int depth[100010];
int par[100010][20];
int cnt = 0;

void dfs(int u, int p) {
    rev[cnt] = u;
    tin[u] = cnt++;
    depth[u] = depth[p] + 1;
    par[u][0] = p;
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u);
            child[u].push_back(v);
        }
    }
    tout[u] = cnt;
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u,v);
    int dif = depth[u] - depth[v];
    int jcnt = 0;
    while(dif) {
        if(dif & 1) u = par[u][jcnt];
        jcnt++;
        dif >>= 1;
    }
    if(u == v) {
        return u;
    }
    jcnt = 19;
    while(jcnt >= 0) {
        if(par[u][jcnt] != par[v][jcnt]) u = par[u][jcnt], v = par[v][jcnt];
        --jcnt;
    }
    assert(par[u][0] == par[v][0]);
    return par[u][0];
}

long long Seg[400010];
long long lazy[400010] = {};

void build(int id, int l, int r) {
    if(l + 1 == r) {
        Seg[id] = vini[rev[l]];
        return;
    }
    int m = (l + r) >> 1;
    build(id << 1, l, m);
    build((id << 1) | 1, m, r);
    Seg[id] = Seg[id<<1] + Seg[(id<<1)|1];
}

void update(int id, int x, int y, int l, int r, long long val) {
    if(lazy[id] != 0) {
        Seg[id] += lazy[id] * (r - l);
        if(l + 1 < r) {
            lazy[id<<1] += lazy[id];
            lazy[(id<<1)|1] += lazy[id];
        }
    }
    lazy[id] = 0;
    if(l >= y || r <= x) return;
    if(l >= x && r <= y) {
        Seg[id] += (r - l) * val;
        if(l + 1 < r) {
            lazy[id<<1] += val;
            lazy[(id<<1)|1] += val;
        }
        return;
    }
    int m = (l+r)>>1;
    update(id<<1, x, y, l, m, val);
    update((id<<1)|1, x, y, m, r, val);
    Seg[id] = Seg[id<<1] + Seg[(id<<1)|1];
}

long long find(int id, int x, int y, int l, int r) {
    if(lazy[id] != 0) {
        Seg[id] += lazy[id] * (r - l);
        if(l + 1 < r) {
            lazy[id<<1] += lazy[id];
            lazy[(id<<1)|1] += lazy[id];
        }
    }
    lazy[id] = 0;
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) {
        return Seg[id];
    }
    int m = (l+r)>>1;
    return find(id<<1, x, y, l, m) + find((id<<1)|1, x, y, m, r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        cin >> vini[i];
    }
    for(int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[0] = 0;
    dfs(0,0);
    build(1, 0, n);
    for(int i = 1; i < 20; ++i) {
        for(int j = 0; j < n; ++j) {
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    int r = 0;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1){
            int nr;
            cin >> nr;
            --nr;
            r = nr;
        }
        else if(t == 2) {
            int u, v, x;
            cin >> u >> v >> x;
            --u, --v;
            int w = lca(u,v) ^ lca(u,r) ^ lca(v,r);
            // cerr << "lca: "  << w << endl;

            if(w == r) {
                update(1, 0, n, 0, n, x);
            }
            else if(tin[w] < tin[r] && tout[w] >= tout[r]) {
                int left = 0, right = child[w].size();
                while(left + 1 < right) {
                    int mid = (left + right) >> 1;
                    if(tin[child[w][mid]] <= tin[r]) left = mid;
                    else right = mid;
                }
                update(1, 0, n, 0, n, x);
                update(1, tin[child[w][left]], tout[child[w][left]], 0, n, -x);
            }
            else update(1, tin[w], tout[w], 0, n, x);
        }
        else if(t == 3) {
            int w;
            cin >> w;
            --w;
            long long sum = 0;

            if(w == r) {
                sum = find(1, tin[0], tout[0], 0, n);
            }
            else if(tin[w] < tin[r] && tout[w] >= tout[r]) {
                int left = 0, right = child[w].size();
                while(left + 1 < right) {
                    int mid = (left + right) >> 1;
                    if(tin[child[w][mid]] <= tin[r]) left = mid;
                    else right = mid;
                }
                sum += find(1, 0, n, 0, n);
                sum -= find(1, tin[child[w][left]], tout[child[w][left]], 0, n);
            }
            else {
                // cerr << "here" << endl;
                sum = find(1, tin[w], tout[w], 0, n);
            }
            cout << sum << '\n';
        }
    }
}
