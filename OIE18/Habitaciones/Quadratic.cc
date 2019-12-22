#include <bits/stdc++.h>
using namespace std;

vector<int> adj;
vector<int> vis;

int dfs(int u) {
    vis[u] = 1;
    int v = adj[u];
    if(vis[v]) return 1;
    return 1 + dfs(v);
}

void solve(int n) {
    adj = vector<int>(n);
    for(int i = 0; i < n; ++i) {
        cin >> adj[i];
    }
    for(int i = 0; i < n; ++i) {
        vis = vector<int> (n,0);
        cout << (i ? " " : "") << dfs(i);
    }
    cout << endl;
}

int main() {
    int n;
    while(cin >> n) {
        solve(n);
    }
}
