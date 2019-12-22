#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll oo = 0x3f3f3f3f3f3f3f3fLL;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define has(c, e) ((c).find(e) != (c).end())
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()

struct cosa{
  ll x, y;
  int sign = 1;
  int idx;
};
const ll limit = 1500000;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<cosa> v[2], ans;
  FOR(i, 0, n) {
    int x, y;
    cin >> x >> y;
    v[x<0].push_back({x,y,1,i});
  }
  if(n == 1) return cout << 1 << endl, 0;
  sort(v[0].begin(), v[0].end(), [](cosa& c1, cosa& c2){
      return (c1.x == c2.x ? c1.y > c2.y : c1.x > c2.x);
    });

  sort(v[1].begin(), v[1].end(), [](cosa& c1, cosa& c2){
      return (c1.x == c2.x ? c1.y > c2.y : c1.x > c2.x);
    });
  int wc[4] = {-1,-1,-1,-1};
  for(int I = 0; I < 2; ++I) {
    ll cury = 0;
    for(int i = 0; i + 1 < sz(v[I]); i += 2) {
      int b = (cury > 0 ? 1 : -1);
      if(v[I][i+1].y > v[I][i].y) v[I][i].sign = b, v[I][i+1].sign = -b;
      else v[I][i].sign = -b, v[I][i+1].sign = b;
      cury += v[I][i].y*v[I][i].sign + v[I][i+1].y*v[I][i+1].sign;
      ans.push_back(v[I][i]), ans.push_back(v[I][i+1]);
    }
    if((sz(v[I])&1)) {
      ans.push_back(v[I][sz(v[I])-1]);
      wc[I] = v[I][sz(v[I])-1].idx;
    }
  }

  sort(ans.begin(), ans.end(), [](cosa& c1, cosa& c2) {
      return c1.idx < c2.idx;
    });
  for(int I = -1; I < 2; I += 2) {
    for(int J = -1; J < 2; J += 2) {
      ll x = 0, y = 0;
      FOR(i, 0, n) {
        x += ans[i].x*ans[i].sign;
        y += ans[i].y*ans[i].sign;
      }
      if(x*x + y*y <= limit*limit) {
        FOR(i, 0, n) {
          cout << ans[i].sign << ' ';
        }
        cout << endl;
        return 0;
      }
      x = y = 0;
      FOR(i, 0, n) {
        x += ans[i].x*ans[i].sign*(ans[i].x >= 0 ? 1 : -1);
        y += ans[i].y*ans[i].sign*(ans[i].x >= 0 ? 1 : -1);
      }
      if(x*x + y*y <= limit*limit) {
        FOR(i, 0, n) {
          cout << (ans[i].x >= 0 ? ans[i].sign : -ans[i].sign) << ' ';
        }
        cout << endl;
        return 0;
      }
    }
  }
  while(1);
  return 0;
}
