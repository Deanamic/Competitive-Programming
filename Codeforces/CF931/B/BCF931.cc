#include<bits/stdc++.h>
using namespace std;

int p[1000];

void build(int id, int l, int r) {
	if(l + 1 >= r) {
		p[l] = id;
		return;
	}
	int m = (l + r)/2;
	build(2*id, l, m);
	build(2*id + 1, m, r);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < 300; ++i) {
		p[i] = i/2;
	}
	int a,b;
	cin >> a >> b;
	--a;
	--b;
	build(1, 0, n);
	int r = 0;
	int xa = p[a];
	int xb = p[b];
	while(xa != xb) {
		xa /= 2;
		xb /= 2;
		++r;
	}
	if((1<<r) == n) cout << "Final!" << endl;
	else cout << r << endl;
}
