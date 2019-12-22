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

vector<long double> x, y, z;
long double ax = -1e6,bx = 1e6, ay = -1e6,by = 1e6,az = -1e6,bz = 1e6;
long double mx1,mx2,my1,my2,mz1,mz2;

long double dist(int i, long double mx, long double my, long double mz) {
  long double xx, yy, zz;
  xx = x[i] - mx;
  yy = y[i] - my;
  zz = z[i] - mz;
  return xx * xx + yy * yy + zz * zz;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  x = y = z = vector<long double>(n);
  FOR(i, 0, n) {
    cin >> x[i] >> y[i] >> z[i];
  }
  long double ans;
  int MAXIT = 50;
  FOR(i, 0, MAXIT) {
    mx1 = (2.*ax + bx)/3., mx2 = (ax + 2.*bx)/3.;
    long double ans1, ans2;
    ans1 = ans2 = 0;
    FOR(j, 0, MAXIT) {
      long double yval1, yval2;
      my1 = (2. * ay + by) / 3., my2 = (ay + 2. * by) / 3.;
      FOR(k, 0, MAXIT) {
        long double val1 = 0, val2 = 0;
        long double z1 = (2. * az + bz) / 3.;
        FOR(l, 0, n) {
          val1 = max(dist(l, mx1, my1, z1), val1);
        }
        long double z2 = (az + 2.*bz) / 3.;
        FOR(l, 0, n) {
          val2 = max(dist(l, mx1, my1, z2), val2);
        }
        if(val1 > val2) az = z1;
        else bz = z2;
        yval1 = val1;
      }
      
      FOR(k, 0, MAXIT) {
        long double val1 = 0, val2 = 0;
        long double z1 = (2.* az + bz) / 3.;
        FOR(l, 0, n) {
          val1 = max(dist(l, mx1, my2, z1), val1);
        }
        long double z2 = (az + 2.* bz) / 3.;
        FOR(l, 0, n) {
          val2 = max(dist(l, mx1, my2, z2), val2);
        }
        if(val1 > val2) az = z1;
        else bz = z2;
        yval2 = val1;
      }
      if(yval1 > yval2) ay = my1;
      else by = my2;
      ans1 = yval1;
    }

    FOR(j, 0, MAXIT) {
      my1 = (2. * ay + by) / 3., my2 = (ay + 2. * by) / 3.;
      long double yval1, yval2;
      FOR(k, 0, MAXIT) {
        long double val1 = 0, val2 = 0;
        long double z1 = (2. * az + bz) / 3.;
        FOR(l, 0, n) {
          val1 = max(dist(l, mx2, my1, z1), val1);
        }
        long double z2 = (az + 2. * bz) / 3.;
        FOR(l, 0, n) {
          val2 = max(dist(l, mx2, my1, z2), val2);
        }
        if(val1 > val2) az = z1;
        else bz = z2;
        yval1 = val1;
      }
      FOR(k, 0, MAXIT) {
        long double val1 = 0, val2 = 0;
        long double z1 = (2. * az + bz) / 3.;
        FOR(l, 0, n) {
          val1 = max(dist(l, mx2, my2, z1), val1);
        }
        long double z2 = (az + 2. * bz) / 3.;
        FOR(l, 0, n) {
          val2 = max(dist(l, mx2, my2, z2), val2);
        }
        if(val1 > val2) az = z1;
        else bz = z2;
        yval2 = val1;
      }
      if(yval1 > yval2) ay = my1;
      else by = my2;
      ans2 = yval1;
    }
    if(ans1 > ans2) ax = mx1;
    else bx = mx2;
    ans = ans1;
    cout << ans << endl;
  }
  cout << fixed << setprecision(10) << sqrt(ans) << endl;
	return 0;
}
