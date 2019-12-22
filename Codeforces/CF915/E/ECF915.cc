#include<bits/stdc++.h>
using namespace std;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

unordered_map<int,int> &M = *(new unordered_map<int,int>);
int V[1000000], value[1000000];

struct Node {
	int l, r;
	int w, nw;
	int lazy; //0 no change, 1 work, 2 no work
	int length;
};

struct query{
	int l, r, k;
};

Node Seg[2500000];

void build(int id, int l, int r) {
	if(l + 1 >= r) {
		Seg[id] = {l, r, value[l], 0, 0, value[l]};
		return;
	}
	int m = (l+r)>>1;
	build(id<<1, l , m);
	build((id<<1)|1, m, r);
	Seg[id] = {l, r, Seg[(id<<1)].w + Seg[(id<<1)|1].w, 0, 0, Seg[(id<<1)].w + Seg[(id<<1)|1].w};
}

void update(int id, int l, int r, const int& x,const int& y,const int& mode) {
	if(Seg[id].lazy == 1) {
		Seg[id].w = Seg[id].length;
		Seg[id].nw = 0;
		if(l + 1 < r) {
			Seg[id<<1].lazy = 1;
			Seg[(id<<1)|1].lazy = 1;
		}
	}
	if(Seg[id].lazy == 2) {
		Seg[id].nw = Seg[id].length;
		Seg[id].w = 0;
		if(l + 1 < r) {
			Seg[id<<1].lazy = 2;
			Seg[(id<<1)|1].lazy = 2;
		}
	}
	Seg[id].lazy = 0;


	if(l >= y || r <= x) return;
	if(l >= x && r <= y) {
		if(mode == 1) {
			Seg[id].w = Seg[id].length;
			Seg[id].nw = 0;
			if(l + 1 < r) {
				Seg[id<<1].lazy = 1;
				Seg[(id<<1)|1].lazy = 1;
			}
		}
		if(mode == 2){
			Seg[id].nw = Seg[id].length;
			Seg[id].w = 0;
			if(l + 1 < r) {
				Seg[id<<1].lazy = 2;
				Seg[(id<<1)|1].lazy = 2;
			}
		}
		return;
	}

	int m = (l+r)>>1;
	update(id*2, l, m, x, y, mode);
	update((id<<1)|1, m, r, x ,y , mode);
	Seg[id].nw = Seg[id*2].nw + Seg[(id<<1)|1].nw;
	Seg[id].w = Seg[id*2].w + Seg[(id<<1)|1].w;
}

inline int find(int id, int l, int r, int x, int y) {
	if(Seg[id].lazy == 1) {
		Seg[id].w = Seg[id].length;
		Seg[id].nw = 0;
		if(l + 1 < r) {
			Seg[id<<1].lazy = 1;
			Seg[(id<<1)|1].lazy = 1;
		}
	}
	if(Seg[id].lazy == 2) {
		Seg[id].nw = Seg[id].length;
		Seg[id].w = 0;
		if(l + 1 < r) {
			Seg[id<<1].lazy = 2;
			Seg[(id<<1)|1].lazy = 2;
		}
	}
	Seg[id].lazy = 0;

	if(l >= y || r <= x) return 0;
	if(l >= x && r <= y) {
		return Seg[id].w;
	}
	int m = (l+r)>>1;
	return find(id<<1, l, m, x, y) + find((id<<1)|1, m, r, x, y);
}

int main(){
	M.reserve(700000);
	M.max_load_factor(0.25);
	int n, q;
	scanf("%d%d", &n, &q);
	int p = q;
	vector<query> Q;
	set<int> &S = *(new set<int>);
	S.insert(n);
	S.insert(n+1);
	S.insert(1);

	int mx = 0;
	while(p--) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		Q.push_back({l,r,k});
		S.insert(l);
		S.insert(r + 1);
	}

	int it = 0;
	for(int x : S) {
		V[it] = x, M[x] = it;
		it++;
	}
	for(int i = 0; i < S.size(); ++i) {
		value[i] = (i + 1 == S.size() ? 0 : V[i+1] - V[i]);
	}
	build(1, 0, S.size());
	for(int i = 0; i < q; ++i) {
		update(1, 0, S.size(), M[Q[i].l], M[Q[i].r + 1], 3 - Q[i].k);
	    printf("%d ", find(1, 0, S.size(), 0, S.size()));
	}
}
