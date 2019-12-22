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

void solve(){
    cin >> N;
    vector < int > tinc(N, 0);
    //~ for(int i = 0; i < N; i++) cout << i << ' ' << tinc[i] << endl;
    for(int i = 0; i < N; i++){
        int a; cin >> a; a--;
        tinc[a]++;
    }
    //~ for(int i = 0; i < N; i++) cout << i << ' ' << tinc[i] << endl;
    int e; cin >> e;
    for (int i = 0; i < e; i++){
        int a,b;
        cin >> a >> b; a--; b--;
        adj[a][deg[a]] = b; deg[a]++;
        adj[b][deg[b]] = a; deg[b]++;
        cap[a][b] = 1e9;
        cap[b][a] = 1e9;
        w[a][b] = 1;
        w[b][a] = 1;
    }
    int s = N;
    int t = N+1;
    for (int i = 0; i < N; i++){
        if(!tinc[i]){
            adj[i][deg[i]] = t; deg[i]++;
            adj[t][deg[t]] = i; deg[t]++;
            cap[i][t] = 1;
            cap[t][i] = 0;
            w[i][t] = 0;
            w[t][i] = 0;
        }
        if (tinc[i] > 1){
            adj[i][deg[i]] = s; deg[i]++;
            adj[s][deg[s]] = i; deg[s]++;
            cap[i][s] = 0;
            cap[s][i] = tinc[i]-1;
            w[i][s] = 0;
            w[s][i] = 0;
        }
    }
    N+=2;
    maxmin(s,t);
    cout << cost << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
}
