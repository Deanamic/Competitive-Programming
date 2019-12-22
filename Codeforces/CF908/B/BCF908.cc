#include<bits/stdc++.h>
using namespace std;


int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int sx,sy,ex,ey;
string s;
vector<int> com;
int n, m;

char v[60][60];


bool good(int x, int y) {
	if(x < 0 || y < 0) return 0;
	if(x >= n || y >= m) return 0;
	if(v[x][y] == '#') return 0;
	return 1;
}
int check(vector<int> dir) {
	int curx = sx, cury = sy;
	for (int i = 0; i < (int)com.size(); ++i) {
		curx += dx[dir[com[i]]];
		cury += dy[dir[com[i]]];
		if(!good(curx, cury)) return 0;
		if(curx == ex && cury == ey) return 1;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin>> v[i][j];
			if(v[i][j] == 'S') sx = i, sy = j;
			if(v[i][j] == 'E') ex = i, ey = j;
		}
	}
	int cnt = 0;
	cin >> s;
	for(char c : s) com.push_back(c-'0');
	vector<int> dir = {0,1,2,3};
	do {
		cnt += check(dir);
	} while (next_permutation(dir.begin(), dir.end()));
	cout << cnt << endl;
}
