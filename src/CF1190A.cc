#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> v(m);
  for(int i = 0; i < m; ++i) {
    cin >> v[i];
  }
  ll rgt = k;
  int cnt = 0;
  int pt = 0;
  while(pt < m) {
    int elim = 0;
    while(pt < m && rgt >= v[pt]) {
      pt++;
      ++elim;
    }
    if(elim) rgt += elim, ++cnt;
    else {
      ll x = v[pt];
      ll tmp = (x - rgt + k - 1)/k;
      rgt += tmp*k;
    }
  }
  cout << cnt << endl;
}
