#include <bits/stdc++.h>
using namespace std;

//subcaso 1

#define SZ 1024
const int oo = 0x3fffffff;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main() {
    int x, y;
    while(cin >> x >> y) {
        y -= 1000000;
        int Q;
        cin >> Q;

        vector<vector<int>> d(SZ, vector<int> (SZ, oo));

        queue<pair<int,int>> q;
        q.push({x,y});
        d[x][y] = 0;
        for(;q.size(); q.pop()) {
            int cx = q.front().first, cy = q.front().second;
            for(int i = 0; i < 4; ++i) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx >= 0 && nx < SZ && ny >= 0 && ny < SZ && d[nx][ny] >= oo) {
                    d[nx][ny] = d[cx][cy] + 1;
                    q.push({nx,ny});
                }
            }
        }
        while(Q--) {
            int a,b;
            cin >> a >> b;
            b -= 1000000;
            cout << d[a][b];
            if(!Q) cout << endl;
            else cout << ' ';
        }
    }
}
