#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	long long sum = 0;
	for(int i = 0; i < n; ++i) {
		cin >> v[i].first;
		sum += v[i].first;
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	if(v[0].first > sum - v[0].first) return cout << "impossible" << endl, 0;
	else {
		for(int i = 0; i < n; ++i) cout << v[i].second << ' ';
		cout << endl;
	}
}
