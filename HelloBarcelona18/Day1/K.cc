#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll oo = 0x3f3f3f3f3f3f3f3fLL;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define has(c, e) ((c).find(e) != (c).end())
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()
struct SparseTable {
    vector<vector<int> > ST;
    vector<int> P;
    vector<int> v;
    int N;
    int MAXLOG = 0;

    void build(int n, vector<int> V){
        N = n;
        v = V;
        while ((1 << MAXLOG) <= N) ++MAXLOG;
        ST = vector<vector<int> > (N, vector<int> (MAXLOG));
        P = vector<int> (N+1);
        int LOG = 0;
        for(int i = 1; i < N + 1; ++i){
            P[i] = ((1<<LOG) > i ?  LOG-1 : ++LOG-1);
        }

        for(int i = 0; i < N; ++i) ST[i][0] = i;
        for (int j = 1; j < MAXLOG; ++j) {
            for (int i = 0; i + (1 << j) - 1 < N; ++i) {
                if (v[ST[i][j - 1]] < v[ST[i + (1 << (j - 1))][j - 1]])
                     ST[i][j] = ST[i][j - 1];
                else
                     ST[i][j] = ST[i + (1 << (j - 1))][j - 1];
            }
        }
    }

	// minimum in range [l, r] (both inclusive)
    int query(int l, int r){
        int LOG = P[r-l+1];
        return min(v[ST[l][LOG]], v[ST[r - (1 << LOG) + 1][LOG]]);
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  int a[n];
  FOR(i, 0, n) {
    cin >> a[i];
    --a[i];
  }
  int inv = 0;
  ordered_set<int> S;
  int add[n];
  FOR(i, 0, n) {
    inv += (add[a[i]] = int(S.order_of_key(-a[i])));
    S.insert(-a[i]);
  }
  //cout << inv << endl;
  int cnt = 0;
  while(inv - add[cnt] >= k) {
    inv -= add[cnt++];
  }
  vector<int> na(cnt);
  iota(na.begin(), na.begin() + cnt, 0);
  FOR(i, 0, n) if(a[i] >= cnt) na.push_back(a[i]);
  SparseTable ST;
  ST.build(n, na);

  if(inv > k) {
    FOR(i, 0, n) {
      if(na[i] >= cnt && ST.query(i-(min(inv-k,add[na[i]])),i) == na[i]){
        int j = i;
        while(inv > k && j && na[j] < na[j-1]) {
          swap(na[j], na[j-1]);
          j--;
          --inv;
        }
      }
    }
  }
  for(int i : na) cout << i+1 << '\n';
	return 0;
}
