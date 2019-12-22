#include<bits/stdc++.h>
using namespace std;

#define IRON 0
#define COP 1
#define IC 2

const int oo = 10000000;
int dp[100010][3];
vector<int> adj[2][100010];
int vis[100010];
void dfs(int u) {
	vis[u] = 1;
	for(int v : adj[0][u]) {
		if(!vis[v]) dfs(v);
		for(int i = 0; i < 3; ++i) dp[u][i] = min(dp[u][i], 1 + dp[v][i]);
	}
	dp[u][IC] = min(dp[u][IC], dp[u][IRON] + dp[u][COP]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
    for(int i = 0; i < 100010; ++i) for(int j = 0; j < 3; ++j) dp[i][j] = oo;
	queue<int> q[3];
	for(int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		dp[x-1][IRON] = 0;
		q[0].push(x-1);
		q[2].push(x-1);
	}
	for(int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		dp[x-1][COP] = 0;
		q[1].push(x-1);
		q[2].push(x-1);
	}
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		for(int i = 0; i < a; ++i) {
			int x;
			cin >> x;
			--x;
			adj[0][i].push_back(x);
			adj[1][x].push_back(i);
		}
	}

	while(q[0].size()) {
		int u = q[0].front(); q[0].pop();
		for(int v : adj[1][u]) {
			if(dp[v][IRON] == oo) {
				dp[v][IRON] = dp[u][IRON] + 1;
				q[0].push(v);
			}
		}
	}

	while(q[1].size()) {
		int u = q[1].front(); q[1].pop();
		for(int v : adj[1][u]) {
			if(dp[v][COP] == oo) {
				dp[v][COP] = dp[u][COP] + 1;
				q[1].push(v);
			}
		}
	}
	for(int i = 0; i < n; ++i) 	dp[i][IC] = dp[i][IRON] + dp[i][COP];

	while(q[2].size()) {
		int u = q[2].front(); q[2].pop();
		for(int v : adj[1][u]) {
			if(dp[v][IC] >= oo) {
				dp[v][IC] = min(dp[v][IC], dp[u][IC] + 1);
				q[2].push(v);
			}
		}
	}
	// for(int i = 0; i < n; ++i) {
		// for(int x : adj[0][i]) {
			// dp[i][IRON] = min(dp[i][IRON], 1 + dp[x][IRON]);
			// dp[i][COP] = min(dp[i][COP], 1 + dp[x][COP]);
		// }
	// }
	// memset(vis, 0, sizeof(vis));
	// dfs(0);
	if(dp[0][IC] >= oo) cout << "impossible" << endl;
	else cout << dp[0][IC] << endl;
}
