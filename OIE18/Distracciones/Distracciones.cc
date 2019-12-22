#include <bits/stdc++.h>
using namespace std;

struct num{
    int n, cnt = 0;

    num(int x):n(x){}

    num(int x, int y):n(x), cnt(y){}

    void operator++(){cnt++;}
};

int main() {
    int n;
    cin >> n;
    vector<num> v;
    v.push_back(num(1,1));
    for(int i = 0; i < n-1; ++i) {
        vector<num> tmp;
        for(auto& j : v) {
            if(tmp.size() && tmp[tmp.size()-1].n == j.cnt) tmp[tmp.size()-1].cnt++;
            else tmp.push_back(num(j.cnt,1));
            if(tmp[tmp.size()-1].n == j.n) tmp[tmp.size()-1].cnt++;
            else tmp.push_back(num(j.n, 1));
        }
        swap(tmp, v);
    }
    for(auto& i : v) cout << i.cnt << i.n;
    cout << endl;
}
