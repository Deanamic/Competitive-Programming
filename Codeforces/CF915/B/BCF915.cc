#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, p, l ,r;
	cin >> n >> p >> l >> r;
	if(l == 1 && r == n) return cout << 0 << endl, 0;
	if(l == 1) return cout << abs(p-r) + 1 << endl, 0;
	if(r == n) return cout << abs(p-l) + 1 << endl, 0;
	int ans1 = 0, ans2 = 0;
	ans1 += abs(l-p);
	ans2 += abs(r-p);
	cout << min(ans1,ans2) + 2 + abs(l-r)  << endl;
}
