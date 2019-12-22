#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n];
	int ans = 10000;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		if(k%a[i] == 0) ans = min(k/a[i], ans);
	}
	cout << ans << endl;
}
