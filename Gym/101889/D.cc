#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
using namespace std;

typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef long double ld;

const int sz = 200, numb = 100010/sz;


int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(0);
  int l, c, n;
  scanf("%d%d%d",&l,&c,&n);
  //cin >> l >> c >> n;
  vector<unordered_map<int, int>> vs(numb);
  for (int i = 0; i < numb; ++i) {
    vs[i].reserve(100);
    vs[i].max_load_factor(0.5);
  }


  vector<int> vals(l);
  for (int i = 0; i < l; ++i){
    vs[i/sz][1]++;
    vals[i] = 1;
  }

  for (int i = 0; i < n; ++i){

    int p, x, a, b;
    scanf("%d%d%d%d",&p,&x,&a,&b);
    //cin >> p >> x >> a >> b;
    ll s= 0;
    for (int j = 0; j < numb; ++j)
      if (vs[j].count(p)) s += vs[j][p];
    int m1 = (a+s*s)%l, m2 = (a+(s+b)*(s+b))%l;
    if (m1 > m2) swap(m1, m2);

    int b1 = m1/sz, b2 = ((m2)/sz);

    if ((vs[b1].size() == 1)){
      for (int j = b1*sz; j < (b1+1)*sz and j < l; ++j) vals[j] = vs[b1].begin()->first;
    }
    for (int j = m1; j < (b1+1)*sz and j <= m2; ++j){
      vs[b1][vals[j]]--;
      vs[b1][x]++;
      vals[j] = x;
    }

    for (int j = b1+1; j < b2; ++j){
      vs[j].clear();
      vs[j][x] = sz;
    }

    if (b1 != b2){
      if ((vs[b2].size() == 1)){
        for (int j = b2*sz; j < (b2+1)*sz and j < l; ++j) vals[j] = vs[b2].begin()->first;
      }
      for (int j = b2*sz; j <= m2; ++j){
        vs[b2][vals[j]]--;
        vs[b2][x]++;
        vals[j] = x;
      }
    }
  }

  int res = 0;
  for (int i = 1; i <= c; ++i){
    int ans = 0;
    for (int j = 0; j < numb; ++j){
      if (vs[j].count(i))
        ans += vs[j][i];
    }
    res = max(ans, res);
  }
  printf("%d\n",res);
  //cout << res << endl;

}
