#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int h;
	cin >> h;
	++h;
	int ch = -1;
	int v[h];
	for(int i = 0; i < h; ++i) {
		cin >> v[i];
		if(ch == -1 && i) {
			if(v[i-1] > 1 && v[i] > 1) ch = i;
		}
	}
	if(ch == -1) cout << "perfect" << endl;
	else {
		cout << "ambiguous" << endl;
		cout << 0 << ' ';
		int lst = 1;
		for(int i = 1; i < h; ++i) {
			for(int j = 0; j < v[i]; ++j) {
				cout << lst << ' ';
			}
			lst += v[i];
		}
		cout << endl;
		cout << 0 << ' ';
		lst = 1;
		for(int i = 1; i < h; ++i) {
			for(int j = 0; j < v[i]; ++j) {
				if(i == ch) {
					if(j) cout << lst-1 << ' ';
					else cout << lst << ' ';
				}
				else cout << lst << ' ';
			}
			lst += v[i];
		}
		cout << endl;
	}
}
