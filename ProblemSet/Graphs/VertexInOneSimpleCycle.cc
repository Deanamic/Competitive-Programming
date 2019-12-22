/**
 * Judge: http://codeforces.com/contest/962/problem/F
 * Contest: Codeforces Educational Round 42
 * Status: Not Submitted
 * Description: Given a graph with N nodes, find the vertex which belong to only one simple cycle
 * Solution: http://codeforces.com/blog/entry/58869?locale=en
 **/

int p[100010];
int vis[100010];
int f[100010];
int root(int x) {
    return (p[x] == -1 ? x: p[x] = root(p[x]));
}

int dfs(int u, int pu) {
    vis[u] = 1;
    f[u] = pu;
    for(int v : adj[u]) {
        if(v != pu) {
            if(vis[v] == 1) {
                //this is a cycle
            }
            else if(vis[v] == 0) dfs(v, u);
        }
    }
    vis[u] = 2;
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
