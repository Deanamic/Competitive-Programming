#include <bits/stdc++.h>

using namespace std;

struct path{
    int a, b, lc, d;
};


int n, c;
vector <vector <int> >g;
vector <path>v;
vector <int> d;
vector <vector <int> >l;
vector <int>pare;

void dfs(int u, int dist, int pre) {
    if (d[u] != -1) return;
    l[u][0] = pre;
    d[u] = dist;
    for (int i = 0; i < g[u].size(); ++i) {
        dfs(g[u][i], dist+1, u);
    }
}

int calc(int a, int prof) {
    int x = c;
    while (d[a] > prof) {
        if (prof + (1<<x) <= d[a]) a = l[a][x];
        x--;
    }
    return a;
}

int lca(int a, int b) {
    if (a == b) return a;
    int x = c;
    while (x >= 0) {
        if (l[a][x] != l[b][x]) {
            a = l[a][x];
            b = l[b][x];
        }
        x--;
    }
    return l[a][0];
}

int mfset(int u) {
    if (pare[u] == -1) return u;
    return pare[u] = mfset(pare[u]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    g = vector <vector <int> >(n);
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int m;
    cin >> m;
    v = vector <path>(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        v[i].a = x;
        v[i].b = y;
    }
    d = vector <int>(n, -1);
    int t = n;
    c = 0;
    while (t) {
        ++c;
        t /= 2;
    }
    l = vector <vector <int> >(n, vector <int>(c));
    dfs(0, 0, 0);
    for (int i = 1; i < c+1; ++i) {
        for (int j = 0; j < n; ++j) {
            l[j][i] = l[l[j][i-1]][i-1];
        }
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int x = v[i].a;
        int y = v[i].b;
        if (d[x] > d[y]) {
            x = calc(x, d[y]);
        }
        else y = calc(y, d[x]);
        v[i].lc = lca(x, y);
        adj[v[i].lc].push_back(i);
        v[i].d = d[v[i].lc];
    }
    vector <int> ans;
    pare = vector <int>(n, -1);
    vector <int> dr(n,0);

    vector<int> perdojordi(n);
    for(int i = 0; i < n; ++i) perdojordi[i] = i;
    sort(perdojordi.begin(), perdojordi.end(), [](auto a, auto b) {
       return d[a] > d[b];
    });

    for(int I = 0; I < n; ++I) {
        int u = perdojordi[I];
        for(int i : adj[u]) {
            auto cur = v[i];
            if(!(dr[mfset(cur.a)] || dr[mfset(cur.b)])) {
                dr[u] = 1;
            }
        }
        if(!dr[u]) pare[mfset(u)] = mfset(l[u][0]);
    }
    for (int i = 0; i < n; ++i) {
        if(dr[i]) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] + 1 << " ";
    cout << endl;
}
