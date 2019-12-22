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

template <class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};

template <class P>
int sideOf(const P& s, const P& e, const P& p) {
	auto a = (e-s).cross(p-s);
	return (a > 0) - (a < 0);
}

const int MAXIT = 100;
const double PPI = double(2)*acos(-1);

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<Point<double>> v(n);
  vector<pair<double,int>> ans(10, {-1,-1});
  FOR(i, 0, 9) ans[i].second = i;
  FOR(i, 0, n) cin >> v[i].x >> v[i].y;

  FOR(i, 3, 9) {
    double Ab, As;
    double l = 0, r = 1e7;
    FOR(II, 0, MAXIT) {
      double m = (l + r)/2.0;
      vector<Point<double>> Pol(i);
      FOR(j, 0, i) Pol[j] = Point<double>{m*cos(PPI*double(j)/(double)(i)), m*sin(PPI*double(j)/(double)(i))};
      int flag = 1;
      for(int j = 0; flag && j < n; ++j) {
        int cur = 1;
        FOR(k, 0, i) {
          cur = min(cur, sideOf(Pol[k], Pol[(k+1)%i], v[j]));
        }
        //si cur -1 continue podent sent bo (tots els punts son left)
        if(cur <= 0) flag = 0;
      }
      if(flag) r = m;
      else l = m;
    }
    Ab = l;
    l = 0, r = 1e7;
    FOR(II, 0, MAXIT) {
      double m = (l + r)/2.0;
      vector<Point<double>> Pol(i);
      FOR(j, 0, i) Pol[j] = Point<double>{m*cos(PPI*double(j)/(double)(i)), m*sin(PPI*double(j)/(double)(i))};
      int flag = 1;
      for(int j = 0; flag && j < n; ++j) {
        int cur = 1;
        FOR(k, 0, i) {
          cur = min(cur, sideOf(Pol[k], Pol[(k+1)%i], v[j]));
        }
        //si cur es -1 el punt es interior, si tinc un interior lhe de fer mes petit
        if(cur >= 0) flag = 0;
      }
      if(flag) l = m;
      else r = m;
    }
    //cout << i << ' ' << As << ' ' << Ab << endl;
    As = l;
    ans[i].first = (As*As)/(Ab*Ab);
  }
  sort(ans.begin(), ans.end());
  cout << ans.back().second << ' ' << fixed << setprecision(10) << ans.back().first << endl;
	return 0;
}
