#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;
vector<int> ans;

bool dfs(int u, int goal) {
    if(u == goal) return 1;
    vis[u] = 1;
    for(int v : adj[u]) {
        if(!vis[v]) if(dfs(v, goal)) return 1;
    }
    return 0;
}

void solve(int n) {
    adj = vector<vector<int>>(n);
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    ans = vector<int>(n,0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            vis = vector<int>(n,0);
            if(dfs(j,i)) ans[i]++;
        }
    }
    for(int i = 0; i < n; ++i) {
        cout << (i ? " " : "") << ans[i];
    }
    cout << endl;
}

int main() {
    int n;
    while(cin >> n) {
        solve(n);
    }
}
