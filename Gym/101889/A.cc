#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


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
bool segmentIntersectionQ(P s1, P e1, P s2, P e2) {
	if (e1 == s1) {
		if (e2 == s2) return e1 == e2;
		swap(s1,s2); swap(e1,e2);
	}
	P v1 = e1-s1, v2 = e2-s2, d = s2-s1;
	auto a = v1.cross(v2), a1 = d.cross(v1), a2 = d.cross(v2);
	if (a == 0) { // parallel
		auto b1 = s1.dot(v1), c1 = e1.dot(v1),
      b2 = s2.dot(v1), c2 = e2.dot(v1);
		return !a1 && max(b1,min(b2,c2)) <= min(c1,max(b2,c2));
	}
	if (a < 0) { a = -a; a1 = -a1; a2 = -a2; }
	return (0 <= a1 && a1 <= a && 0 <= a2 && a2 <= a);
}

double h = 0;
double eps = 0.0001;
vector<vector<pair<Point<double>,Point<double>>>> lv, rv;

bool check(int I, int J, double m) {
  int it1,it2;
  const Point<double>pt(m,0);
  it1 = it2 = 0;
  double ml, mr;
  ml = mr = 0;
  FOR(i, 0, sz(rv[I])) mr = min(mr, min(rv[I][i].first.x, rv[I][i].second.x));
  FOR(j, 0, sz(lv[J])) ml = max(ml, max(lv[J][j].first.x, lv[J][j].second.x));
  if(ml < mr) return false;
  while(it1 < sz(rv[I]) && it2 < sz(lv[J])){
    if(segmentIntersectionQ(rv[I][it1].first, rv[I][it1].second, lv[J][it2].first + pt, lv[J][it2].second + pt)) {
      return true;
    }
    if(rv[I][it1].second.y < lv[J][it2].second.y && it1 + 1 < sz(rv[I])) ++it1;
    else if(it2 + 1 < sz(lv[J])) ++it2;
    else ++it1;
  }
  return false;
}

const int MAXIT = 50;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<vector<Point<double>>> v(n);
  rv.resize(n);
  lv.resize(n);
  FOR(i, 0, n) {
    int k;
    cin >> k;
    FOR(j, 0, k) {
      int x, y;
      cin >> x >> y;
      v[i].emplace_back(x,y);
      h = max((double)y, h);
    }
  }
  FOR(i, 0, n) {
    int st = 1;
    FOR(j, 0, sz(v[i])) {
      if(v[i][j].y > v[i][(j+1)%sz(v[i])].y) st = 0;
      if(st) rv[i].emplace_back(v[i][j],v[i][(j+1)%sz(v[i])]);
    }
    st = 1;
    FORD(j, 0, sz(v[i])) {
      if(v[i][j].y < v[i][(j-1+sz(v[i]))%sz(v[i])].y || v[i][(j-1+sz(v[i]))%sz(v[i])].y + eps > h) lv[i].emplace_back(v[i][j],v[i][(j-1+sz(v[i]))%sz(v[i])]);
      else if(v[i][j].y - eps < 0)  lv[i].emplace_back(v[i][j],v[i][(j-1+sz(v[i]))%sz(v[i])]);
    }
    //lv[i].emplace_back(v[i][0], v[i][1]);
    sort(lv[i].begin(), lv[i].end(), [](auto a1, auto a2) {
                                       //if(abs(a1.second.y - a2.second.y) < eps)
                                         return a1.first.y < a2.first.y;
                                       return a1.second.y < a2.second.y;
                                     });
    sort(rv[i].begin(), rv[i].end(), [](auto a1, auto a2) {
                                       //if(abs(a1.second.y - a2.second.y) < eps)
                                         return a1.first.y < a2.first.y;
                                       return a1.second.y < a2.second.y;
                                     });
  }
  double dist[n][n];
  FOR(i, 0, n) {
    FOR(j, 0, n) {
      if(i != j) {
        double l = 0, r = 1e9;
        FOR(K, 0, MAXIT) {
          double m = (l+r)/2;
          (check(i, j, m) ? l : r) = m;
        }
        dist[i][j] = l;
      }
    }
  }
  // FOR(i,0,n){FOR(j,0,n) cout << dist[i][j] << ' ';cout << endl;}
  vector<vector<double>> dp(1<<n, vector<double>(n,1e15));
  FOR(i, 0, n) {
    double lft = 0;
    FOR(k, 0, v[i].size()) lft = min(lft, v[i][k].x);
    dp[(1<<i)][i] = abs(lft);
    if(n == 1) {
      double rth = 0;
      FOR(k, 0, v[i].size()) rth = max(rth, v[i][k].x);
      dp[1][0] += rth;
    }
  }
  FOR(i, 0, 1<<n) {
    FOR(j, 0, n) {
      FOR(l, 0, n) {
        if(j != l && (i & (1<<l)) && !(i & (1<<j))) {
          int nwMask = i | (1<<j);
          double curans = dp[i][l] + dist[l][j];
          if(nwMask == (1<<n)-1) {
            double rth = 0;
            FOR(k, 0, v[j].size()) rth = max(rth, v[j][k].x);
            curans += rth;
          }
          dp[nwMask][j] = min(curans, dp[nwMask][j]);
        }
      }
    }
  }
  double mn = 1e15;
  FOR(i, 0, n) mn = min(mn, dp[(1<<n)-1][i]);
  cout << fixed << setprecision(3) <<  mn << endl;
  return 0;
}
