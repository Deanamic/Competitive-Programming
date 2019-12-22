#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v[2];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    int n[2];
    cin >> n[0] >> n[1];
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < n[i]; ++j){
            int x,y;
            cin >> x >> y;
            v[i].push_back({min(x,y), max(x,y)});
        }
    }
    set<int> cand;
    int val = -1;
    for(int i = 0; i < n[0]; ++i) {
        for(int j = 0; j < n[1]; ++j) {
            int app = 0;
            int curval = 0;
            for(int k = 1; k <=9; ++k) {
                if((v[0][i].first == k || v[0][i].second == k) && (v[1][j].first == k || v[1][j].second == k)) {
                    app++;
                    curval = k;
                }
            }
            if(app == 1) {
                cand.insert(curval);
            }
        }
    }

    if(cand.size() == 1) return cout << *cand.begin() << endl, 0;
    int ded = 1;
    for(int i = 0; i < n[0]; ++i) {
        set<int> curs;
        for(int j = 0; j < n[1]; ++j) {
            int cnt = 0;
            int curval = 0;
            for(int k = 1; k <= 9; ++k) {
                if((v[0][i].first == k || v[0][i].second == k) && (v[1][j].first == k || v[1][j].second == k)) {
                    cnt++;
                    curval = k;
                }
            }
            if(cnt == 1) curs.insert(curval);
        }
        if(curs.size() > 1) {
            ded = 0;
        }
    }
    if(ded) return cout << 0 << endl, 0;
    cout << -1 << endl;


}
