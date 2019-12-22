#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long binpow(long long a, long long k) {
	if(k == 0) return 1;
	if(k & 1) return (a * binpow((a*a)%MOD, k>>1))%MOD;
	return binpow((a*a)%MOD, k>>1)%MOD;
}

long long inv(long long a) {
	return binpow(a, MOD - 2)%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long k, pa, pb;
	cin >> k >> pa >> pb;
	long long ans = k*(((2*pa+pb)*(pa+pb))%MOD);
	ans %= MOD;
	long long d = ((pa + pb) * (pa + pb)) + pb * (pa+pb) + (pa*pa);
	d %= MOD;
	cout << (ans * inv(d))%MOD << endl;
}
