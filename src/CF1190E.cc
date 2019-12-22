#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()
#define debug(x) cerr << #x << ": " << x << endl;

const double C_PI = acos(-1);
int n;
vector<pair<double, double>> v;

bool can(double r, int k) {
  vector<pair<double,double>> w;
  for(auto p : v) {
    double d = sqrt(1.*p.first*p.first + 1.*p.second*p.second);
    double angRange = acos(r/d);
    double angle = acos(p.first/d);
    if(p.second < 0) angle = 2*C_PI - angle;
    double a = angle - angRange;
    double b = angle + angRange;
    if(a > 2*C_PI) a -= 2*C_PI, b -= 2*C_PI;
    w.push_back({a,b});
  }
  sort(w.begin(), w.end(),[](auto a, auto b) {
                            return (a.second == b.second ?
                                    a.first < b.first :
                                    a.second < b.second);});
  FOR(i, 0, n)  w.push_back({w[i].first + 2*C_PI, w[i].second + 2*C_PI});
  int LOGK = 20;
  int x = 1;
  vector<vi> dp(n, vi(LOGK));
  FOR(i, 0, n) {
    while(x < sz(w) && w[i].second >= w[x].first) ++x;
    dp[i][0] = x - i;
  }
  FOR(i, 0, LOGK-1) FOR(j, 0, n) dp[j][i+1] = min(n, dp[j][i] + dp[(j+dp[j][i])%n][i]);
  FOR(i,0, n) {int cur=0; FOR(j,0,LOGK) {if(k&(1<<j)) {cur = min(n,cur+dp[(i+cur)%n][j]); if(cur>=n) return true;}}}
  return false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(14);
  int k;
  cin >> n >> k;
  double l = 0, r = 1e6;
  FOR(i, 0, n) {
    double x, y;
    cin >> x >> y;
    if(x == 0 && y == 0) return cout << 0 << endl, 0;
    v.emplace_back(x, y);
    r = min(r, sqrt(1.*x*x+1.*y*y));
  }
  FOR(i, 0, 80) {
    if(fabs(l-r) < 5e-12) break;
    double m = l+(r-l)/2;
    if(can(m, k)) l = m;
    else r = m;
  }
  cout << l << endl;
}
