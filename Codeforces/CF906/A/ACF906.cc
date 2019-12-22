#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> can(26,1);
	int n;
	cin >> n;
    int isUnique = 0;
	char Unique;
	int shock = 0;
	for(int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		if(c == '!') {
			string s;
			cin >> s;
			if(isUnique) {
				++shock;
				continue;
			}
			set<int> st;
			for(char c : s) {
			    st.insert(c-'a');
			}

			for(int j = 0; j < 26; ++j) {
				if(!st.count(j)) can[j] = 0;
			}
			char ans;
			int cnt = 0;
			for(int j = 0; j < 26; ++j) {
				if(can[j]){
					cnt++;
					ans = j + 'a';
				}
			}
			if(cnt == 1) {
				isUnique = 1;
				Unique = ans;
			}
		}
		else if(c == '.') {
			string s;
			cin >> s;
			if(isUnique) continue;
			set<int> st;
			for(char c : s) {
			    st.insert(c-'a');
			}

			for(int j = 0; j < 26; ++j) {
				if(can[j] && st.count(j)) can[j] = 0;
			}
			char ans;
			int cnt = 0;
			for(int j = 0; j < 26; ++j) {
				if(can[j]){
					cnt++;
					ans = j + 'a';
				}
			}
			if(cnt == 1) {
				isUnique = 1;
				Unique = ans;
			}
		}else {
			char c1;
			cin >> c1;
			if(isUnique && c1 == Unique) {
				cout << shock << endl;
				return 0;
			}
			if(isUnique) ++shock;
			for(int j = 0; j < 26; ++j) {
				if(can[j] && (j+'a') == c1) can[j] = 0;
			}
			char ans;
			int cnt = 0;
			for(int j = 0; j < 26; ++j) {
				if(can[j]){
					cnt++;
					ans = j + 'a';
				}
			}
			if(cnt == 1) {
				isUnique = 1;
				Unique = ans;
			}

		}
	}
	cout << shock << endl;
}
