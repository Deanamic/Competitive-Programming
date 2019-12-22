#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(15);
	string s;
	cin >> s;
	int n = s.size();
	s = s + s;
	vector<vector<string>> v(26);
	for(int i = 0 ; i < n; ++i) {
		string s1 = s.substr(i, n);
		v[s1[0]-'a'].push_back(s1);
	}
	int can = 0;
	for(int i = 0; i < 26; ++i) {
		int mx = 0;
		for(int j = 1; v[i].size() and j < n; ++j) {
			int cnt[26] = {};
			bool b = 1;

			for(int k = 0; k < v[i].size(); ++k) {
				char c = v[i][k][j];
				cnt[c-'a']++;
			}
			int cur = 0;
		    for(int k = 0; k < 26; ++k) {
				if(cnt[k] == 1) cur++;
			}
			mx = max(cur, mx);
		}
		can += mx;
	}
	// cout << can << endl;
	cout << can/double(n) << endl;
}
