#include<bits/stdc++.h>
using namespace std;

string a, b;

pair<string,bool> greed(vector<int> v, int p) {
	if(p == b.size()) return {"", 1};
	int cur = b[p] - '0';
	if(v[cur]) {
		v[cur]--;
		auto ans = greed(v, p+1);
		if(ans.second) return { char('0'+cur) + ans.first, true};
		v[cur]++;
	}

	int cursmall = -1;
	for(int i = cur - 1; cursmall == -1 && i >= 0; --i) if(v[i]) cursmall = i;
	if(cursmall == -1) return {"", false};
	v[cursmall]--;
    string ans = "";
	ans += char(cursmall + '0');
	for(int i = 9; i >= 0; --i) {
		while(v[i]--) ans += char('0' + i);
	}
	return {ans, true};
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	vector<int> v(11,0);
	for(char c : a) v[c-'0']++;
	if(b.size() > a.size()) {
		string ans = "";
		for(int i = 9; i >= 0; --i) {
			while(v[i]--) ans += char('0' + i);
		}
		return cout << ans << endl, 0;
	}
	cout << greed(v, 0).first << endl;
}
