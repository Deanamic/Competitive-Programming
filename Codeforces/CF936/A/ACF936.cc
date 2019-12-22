#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(14);
	long long k,d,t;
	cin >> k >> d >> t;
	d = ((k+d-1)/d)*d;

	long long dif = d - k;
	long long per = 2*k + dif; //lo que hago cada d tiempo
	t <<= 1;

	//we have to cook for t seconds, on cooks for 2 secs, off cooks for 1 sec
    long long t0 = t/per;
	long long lft = t%per;
	long double ans = t0 * d;

    if(lft <= 2*k) {
		ans += lft/2.0;
		cout << ans << endl;
	}
	else {
		ans += k;
		lft -= 2*k;
		ans += lft;
		cout << ans << endl;
	}


}
