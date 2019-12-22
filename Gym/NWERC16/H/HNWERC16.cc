#include<bits/stdc++.h>
using namespace std;

int n;

long long val(string& s, int pos) {
	if(pos+1 == n) return (s[pos] == '0' ? 1 : 2);
    if(s[pos] == '0') return val(s, pos+1);
	return (1LL<<(n-pos)) - val(s,pos+1) + 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s1, s2;
	cin >> n >> s1 >> s2;
	cout << val(s2, 0) -  val(s1, 0) - 1<< endl;
}
