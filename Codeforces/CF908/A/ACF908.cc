#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    string s;
	cin >> s;
	int cnt = 0;
	set<char> f;
	f.insert('a');
	f.insert('e');
	f.insert('i');
	f.insert('o');
	f.insert('u');
	for(char c : s) {
		if(f.count(c)) ++cnt;
		if(c - '0' >= 0 && c - '0'<= 9) cnt += (c-'0')&1;
	}
	cout << cnt << endl;
}
