#include<bits/stdc++.h>
using namespace std;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	bitset<25> end;
	vector<bitset<25>> adj(n);
	for(int i = 0; i < n; ++i) end[i] = adj[i][i] = 1;
	for(int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x; --y;
		adj[x][y] = 1;
		adj[y][x] = 1;
	}
	bool izi = 1;
	for(int i = 0; i < n; ++i) {
		izi &= (end == adj[i]);
	}
	if(izi) {
		printf("0\n");
		return 0;
	}
	vector<int> best(n+1);
	int ITMAX = 1000000;
	int ord[n];
	for(int i = 0; i < n; ++i) ord[i] = i;
	srand(71);
	while(ITMAX--) {
		vector<int> cur;
		auto tmp = adj;
		random_shuffle(ord, ord+n);
		int it = 0;
		while(cur.size() < best.size()) {
			int cont = ord[it++];
			auto mask = tmp[cont];
			int can = -1;
			int cant = 0;
			for(int i = 0; i < n; ++i) {
				if(mask[i]) {
					tmp[i] |= mask;
					if(tmp[i] == end) can = i;
					else cant = 1;
				}
			}
			cur.push_back(cont);
			if(can != -1 && !cant) {
				if(best.size() > cur.size()) swap(best, cur);
				break;
			}
			else if(can != -1) {
				cur.push_back(can);
				if(best.size() > cur.size()) swap(best, cur);
				break;
			}
		}
	}
	printf("%d\n", (int)best.size());
	for(int i : best) printf("%d ", i+1);
}
