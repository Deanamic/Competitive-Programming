#include<bits/stdc++.h>
using namespace std;

struct pol{
	int deg;
	int a[160];

	pol getpol(pol pa, pol pb) {
		pol ans;
		ans.deg = pa.deg + 1;
		ans.a[0] = 0;
		for(int i = 1; i < ans.deg; ++i) {
			ans.a[i] = pa.a[i-1];
		}
		for(int i = 0; i < pb.deg; ++i) {
			ans.a[i] += pb.a[i];
		}
		for(int i = 0; i < pb.deg; ++i) ans.a[i] %= 2;
		return ans;
	}

};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pol> a(160), b(160);
	a[0].deg = 2;
	a[0].a[1] = 1;
	a[0].a[0] = 0;

	b[0].deg = 1;
	b[0].a[0] = 1;

	for(int i = 1; i < n; ++i) {
		b[i] = a[i-1];
		a[i] = a[i].getpol(a[i-1], b[i-1]);
	}
	cout << a[n-1].deg - 1 << endl;
	int x = (a[n-1].a[a[n-1].deg-1] == -1 ? -1 : 1);
	for(int i = 0; i < a[n-1].deg; ++i) cout << x * a[n-1].a[i] << ' ';
	cout << endl;

	cout << b[n-1].deg - 1 << endl;
	int y = (b[n-1].a[b[n-1].deg-1] == -1 ? -1 : 1);
	for(int i = 0; i < b[n-1].deg; ++i) cout << y * b[n-1].a[i] << ' ';
	cout << endl;


}
