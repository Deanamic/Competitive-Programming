#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100010];
int v[2][100010];
int vis[100010];
int term[100010];
stack<int> st;
bool draw = 0;

int dfs(int x, int p) {
	v[p][x] = 1;
	if(p&1 && term[x]) {
		st.push(x);
		return 1;
	}

	for(int u : adj[x]) {
		if(!v[p^1][u]) {
			if(dfs(u,p^1)) {
				st.push(x);
				return 1;
			}
		}
	}
	return 0;
}

bool cycle(int u){
    vis[u] = 2;
    for(int i : adj[u]){
        if(vis[i] == 2) return true;
        if(!vis[i]) if(cycle(i)) return true;
    }
    vis[u] = 1;
    return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int possible = 0;
	memset(term, 0, sizeof(term));
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if(!x) {
			possible = 1;
			term[i] = 1;
		}
		for(int j = 0; j < x; ++j) {
			int v;
			cin >> v;
			adj[i].push_back(v-1);
		}
	}
	int s;
	cin >> s; --s;
	if(!possible) return cout << "Draw" << endl, 0;
	memset(v, 0, sizeof(v));
	if(dfs(s,0)) {
		cout << "Win" << endl;
		while(st.size()) {
			cout << st.top() + 1 << ' ' ;
			st.pop();
		}
		cout << endl;
	}
	else {
		cout << (cycle(s) ? "Draw" : "Lose") << endl;
	}
}
