#include<bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a[1000];
	long long ans = 1;
	for(int i = 0; i < 1000; ++i) {
		a[i] = ans;
		ans <<= 1;
		ans %= 1000000007;
	}
	for(int i = 0; i < 1000; ++i) {
		for(int j = 0; j < i; ++j) {
			ans = 1;
			for( int k = j; k < i; ++k) {
				ans *= ((a[i] - a[j] + 1000000007)%mod);
				ans %= 1000000007;
			}
			if(ans == 860616440) return cout << i << ' ' << j << endl, 0;
		}
	}
}
