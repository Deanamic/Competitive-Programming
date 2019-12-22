#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int v[2][n];
	map<int, int> m;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		cin >> v[0][i];
		m[v[0][i]] = 1;
	}

	for(int i = 0; i < n; ++i) {
		int x;
		cin >> v[1][i];
		if(m[v[1][i]]) ans = max(ans, v[1][i]);
	}

	set<int> s;
	s.insert(-1);
	for(int i = 0; i < n; ++i) {
		int x = v[0][i];
		if(x < ans) continue;

		if(*(--s.end()) > x) ans = max(x, ans);
		else if(x != *(--s.end())) ans = max(ans, *(--s.end()));

		if(s.count(x)) s.erase(x);
		else s.insert(x);
	}
	s.clear();
	s.insert(-1);
	for(int i = 0; i < n; ++i) {
		int x = v[1][i];
		if(x < ans) continue;
		if(*(--s.end()) > x) ans = max(x, ans);
	  else if(x != *(--s.end()))  ans = max(ans, *(--s.end()));
		if(s.count(x)) s.erase(x);
		else s.insert(x);
	}
	cout << ans << endl;
}
