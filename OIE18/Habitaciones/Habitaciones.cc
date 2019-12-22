#include <bits/stdc++.h>
using namespace std;

vector<int> adj;
vector<int> vis;
vector<int> ans;

pair<int, int> dfs(int u, int d) {
    vis[u] = d;
    int v = adj[u];
    if(ans[v]) return {ans[u] = 1 + ans[v], -1}; //si ya esta calculado ya estoy
    if(vis[v]) { //si vuelvo a un lugar que ya he calculado es un diclo
        ans[u] = d - vis[v] + 1;
        return {vis[v], u};
    }
    auto cur = dfs(v, d + 1);
    if(cur.second > 0) { //si estoy dentro de un ciclo
        ans[u] = ans[cur.second];
        if(vis[u] > cur.first) return cur;
        return {ans[u], -1};
    }
    return {ans[u] = 1 + cur.first, -1}; //si no estoy en un ciclo
}
void solve(int n) {
    adj = vector<int>(n);
    vis = vector<int>(n,0);
    ans = vector<int>(n,0);
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        adj[i] = x;
    }
    for(int i = 0; i < n; ++i) {
        if(!vis[i]) {
            dfs(i, 1);
        }
    }
    for(int i = 0; i < n; ++i) cout << (i ? " " : "") << ans[i];
    cout << endl;
}

int main() {
    int n;
    while(cin >> n) {
        solve(n);
    }
}
