#include<bits/stdc++.h>
using namespace std;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

inline bool good(int i, int j) {
	if(i < 0 || j < 0) return 0;
	if(i >= n || j >= m) return 0;
	return 1;
}

inline bool good(int i) {
	return good(i/m, i%m);
}

inline bool isNeighbour(int i, int j) {
	int xi = i/m;
	int xj = i%m;

	int ni = j/m;
	int nj = j%m;
	for(int k = 0; k < 4; ++k) {
		int ci = xi + dx[k];
		int cj = xj + dy[k];
		if(good(ci, cj)) {
		    if(cj == nj && ci == ni) return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d %d", &n, &m);
	if(n == 2 and m == 2){
		printf("NO\n");
		return 0;
	}
	if(n == 2 and m == 3){
		printf("NO\n");
		return 0;
	}
	if(n == 3 and m == 2){
		printf("NO\n");
		return 0;
	}
	if(n == 1 and (m == 2 || m == 3)) {
		printf("NO\n");
		return 0;
	}
	if((n == 3 || n == 2) and m == 1) {
		printf("NO\n");
		return 0;
	}
	int P = n*m;
	int curans[P];
	for(int i = 0; i < P; ++i) curans[i] = i;
	srand(71);
	while(1) {
		random_shuffle(curans, curans + P);
		int isgood = 1;
		for(int i = 0; isgood && i < P; ++i) {
			if(i+m < P && isNeighbour(curans[i], curans[i+m])){
				isgood = 0;
			}
			if((i%m != m-1) && isNeighbour(curans[i], curans[i+1])){
				isgood = 0;
			}
		}
		if(isgood) {
			printf("YES\n");
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < m; ++j) {
					printf("%d ",curans[i*m + j]+1);
				}
			  printf("\n");
			}
			return 0;
		}
	}
	printf("NO\n");
}
