#include<bits/stdc++.h>
using namespace std;

struct sh {
	int d;
	long double f;
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x,y;
	cin >> x >> y;
	int neg = (x < 0);
	x = abs(x);
	int n;
	cin >> n;
	vector<sh> v(n);
	int tot = y;
	for(int i = 0; i < n; ++i) {
		int l,r;
		cin >> l >> r >> v[i].f;
		v[i].d = r-l;
		tot -= v[i].d;
	}
	v.push_back({tot, 1});
	long double l = 0, r = 1e9;
	for(int i = 0; i < 1e5; ++i) {
		auto m =(l + r)/2;
		long double dis = 0;
		for(int i = 0; i < n+1;++i) {
			dis += v[i].d * m * v[i].f;
		}
		if(dis > x) r = m;
		else l = m;
	}
	if(neg) l*=-1;
	cout << fixed << setprecision(14) << l << endl;
}
