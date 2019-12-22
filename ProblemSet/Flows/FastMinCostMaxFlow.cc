/**
 * Judge: http://codeforces.com/gym/101635
 * Contest: SWERC 2014 Problem G
 * Status: AC
 * Description: Given N places to visit and M cars, find the minimum distance to visit all going through the origin each time.
 * Solution: Consider the problem as a Min weight max matching
 **/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)

const int oo = 1e7;
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
    int n,m;
    cin >> n >> m;
    int x1[n], y1[n];
    int x2[m+n-1] = {}, y2[m+n-1] = {};
    int x,y;
    vi l, r;

    vector<vi> cost(n, vi(m+n-1, 0));
    for(int i = 0; i < n; ++i) {
        cin >> x1[i] >> y1[i];
    }

    for(int i = 0; i < m; ++i) {
        cin >> x2[i] >> y2[i];
    }
    cin >> x >> y;
    for(int i = m; i < m+n; ++i) {
        x2[i] = x;
        y2[i] = y;
    }
    m += n - 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cost[i][j] = abs(x1[i] - x) + abs(y1[i] - y) + abs(x1[i] - x2[j]) + abs(y1[i] - y2[j]);
        }
    }

    cout << min_assignment(cost) << endl;
}
