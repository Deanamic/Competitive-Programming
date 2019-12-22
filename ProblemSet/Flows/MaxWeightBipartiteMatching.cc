/**
 * Judge: http://www.spoj.com/problems/SCITIES/
 * Contest: SPOJ
 * Status: AC
 * Description: Find Max cost bipartite matching
 * Solution: Consider the problem as a Min weight max matching
 **/

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)

const int oo = 1e8;
typedef long long ll;
typedef pair < ll, ll > PLI;
typedef vector<int> vi;

#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())

typedef int value_type;
const value_type inf = 99999999;

value_type min_assignment(const vector<vector<value_type>> &c) {
    const int n = c.size(), m = c[0].size(); // assert(n <= m);
    vector<value_type> v(m), dist(m);        // v: potential
    vector<int> matchL(n,-1), matchR(m,-1);  // matching pairs
    vector<int> index(m), prev(m);
    iota(all(index), 0);

    auto residue = [&](int i, int j) { return c[i][j] - v[j]; };
    for (int f = 0; f < n; ++f) {
        for (int j = 0; j < m; ++j) {
            dist[j] = residue(f, j);
            prev[j] = f;
        }
        value_type w;
        int j, l;
        bool end = 0;
        for (int s = 0, t = 0;;) {
            if (s == t) {
                l = s; w = dist[index[t++]];
                for (int k = t; k < m; ++k) {
                    j = index[k];
                    value_type h = dist[j];
                    if (h <= w) {
                        if (h < w) { t = s; w = h; }
                        index[k] = index[t]; index[t++] = j;
                    }
                }
                for (int k = s; k < t; ++k) {
                    j = index[k];
                    if (matchR[j] < 0) {
                        end = 1;
                        break;
                    }
                }
                if(end) break;
            }
            int q = index[s++], i = matchR[q];
            for (int k = t; k < m; ++k) {
                j = index[k];
                value_type h = residue(i,j) - residue(i,q) + w;
                if (h < dist[j]) {
                    dist[j] = h; prev[j] = i;
                    if (h == w) {
                        if (matchR[j] < 0) {
                            end = 1;
                            break;
                        }
                        index[k] = index[t]; index[t++] = j;
                    }
                }
            }
            if(end) break;
        }
        for(int k = 0; k < l; ++k)
            v[index[k]] += dist[index[k]] - w;
        int i;
        do {
            matchR[j] = i = prev[j];
            swap(j, matchL[i]);
        } while (i != f);
    }
    value_type opt = 0;
    for (int i = 0; i < n; ++i)
        opt += c[i][matchL[i]]; // (i, matchL[i]) is a solution
    return opt;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int c1, c2;
        cin >> c1 >> c2;
        bool sw = 0;
        if(c1 > c2) sw = 1;
        vector<vector<int>> cost;
        if(sw) cost.resize(c2, vector<int> (c1,0));
        else cost.resize(c1, vector<int> (c2,0));
        int a,b,c;
        while(cin >> a >> b >> c, a || b || c) {
            --a, --b;
            if(sw)swap(a,b);
            c = -c;
            cost[a][b] = min(cost[a][b], c);
        }
        cout << -min_assignment(cost) << endl;
    }
}
