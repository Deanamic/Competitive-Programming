#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	cin >> a >> b;
	int x = min(a,b);
	int y = max(a,b);
	int ans = 0;
	int i = 0;
	int j = 0;
	while(x != y) {
		if(i == j) {
			x++;
			ans += ++i;
		}
		else {
			y--;
			ans += ++j;
		}
	}
	cout << ans << endl;
}
