#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000100

int perm[MAXN], pr[MAXN];

int main() {
    int n, lb , ub;
    cin >> n >> lb >> ub;
    assert(ub <= 1000000);
    assert(lb <= ub);
    assert(lb >= 2);
    srand(time(NULL));
    default_random_engine gen;
    uniform_int_distribution<int> distribution(lb,ub);
    for(int I = 0; I < n; ++I) {
        int x = distribution(gen); //number of people
        int dis[x];
        uniform_int_distribution<int> cycle(2, x);
        int c = cycle(gen); //size of cycle
        for(int i = 0; i < c; ++i) dis[i] = (i + 1)%c;
        //now build roads for people left
        int lft = x - c;
        int cur = c;
        while(lft) {
            uniform_int_distribution<int> att(0, x - lft - 1);
            uniform_int_distribution<int> path(1, lft);
            int sz = path(gen);
            int attach = att(gen);
            for(int i = 0; i < sz; ++i) {
                dis[cur+i] = (i == 0 ? attach : cur + i - 1);
            }
            cur += sz;
            lft -= sz;
        }
        iota(perm, perm + x, 0);
        random_shuffle(perm, perm + x);;
        for(int i = 0; i < x; ++i) pr[perm[i]] = perm[dis[i]];
        cout << x << endl;
        for(int i = 0; i < x; ++i) {
            assert(pr[i] < x);
            cout << (i ? " " : "") << pr[i];
        }
        cout << endl;
    }

}
