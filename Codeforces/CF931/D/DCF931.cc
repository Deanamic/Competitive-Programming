#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int mn = 1000000;
	int mx = -1000000;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
		mn = min(v[i], mn);
		mx = max(v[i], mx);
	}
	int cnt[3] = {};
	int ans = n;
	if(mx - mn == 2) {
		int mid = mn + 1;
		for(int i = 0; i < n; ++i) {
			if(v[i] == mn) cnt[0]++;
			else if(v[i] == mx) cnt[2]++;
			else cnt[1]++;
		}
		if((cnt[1]/2) > min(cnt[0],cnt[2])) {
			int cnt1, cnt2;
			cnt1 = cnt2 = cnt[1]/2;
			for(int i = 0; i < n; ++i) {
				if(v[i] == mid) {
					if(cnt1) {
						v[i] += 1;
						cnt1--;
						ans--;
					}
					else if(cnt2) {
						v[i] -= 1;
						cnt2--;
						ans--;
					}
				}
			}
		}
		else {
			int abc = min(cnt[0], cnt[2]);
			int ab = abc;
			for(int i = 0; i < n; ++i) {
				if(v[i] == mn && abc) {
					v[i]++;
					--abc;
					ans--;
				}
				if(v[i] == mx && ab) {
					v[i]--;
					--ab;
					ans--;
				}
			}
			}
	}
	cout << ans << endl;
	for(int i : v) cout << i << ' ';
	cout << endl;
}
