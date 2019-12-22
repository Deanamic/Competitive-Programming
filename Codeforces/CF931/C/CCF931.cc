#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100010];
int d[100010] = {};

void dfs(int x, int dp) {
	d[dp]++;
	for(int u : adj[x]) {
		dfs(u, dp+1);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		adj[x].push_back(i);
	}
	dfs(0, 0);
	int ans = 0;
	for(int i = 0; i < 100010; ++i) ans += d[i] & 1;
	cout << ans << endl;
}
