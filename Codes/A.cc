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

double eps = 0.01;


template <class T>
struct Point {
	typedef Point P;
	T x, y;
  int c;
	explicit Point(T x1=0, T y1=0, int c1 = 1) : x(x1), y(y1), c(c1) {}
  Point(auto x1, auto y1) : x(x1), y(y1) {}
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
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a),c); }
};

using point = Point<long double>;

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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<point> v(n);

  double pend = atan(sqrt(2));
  FOR(i, 0, n) {
    cin >> v[i].x >> v[i].y >> v[i].c;
    v[i] = v[i].rotate(pend);
  }
  sort(v.begin(), v.end(), [](auto a, auto b){
                             return a.x < b.x;
                           });
  vector<point> ans1,ans2;
  int f1,f2;
  f1 = f2 = 1;
  FOR(i, 0, n) {
    if(v[i].c == 1) {
      ans1.emplace_back(v[i].x-eps,-2000 - f1*300);
      ans1.emplace_back(v[i].x-eps,v[i].y+eps);
      ans1.emplace_back(v[i].x+eps,v[i].y+eps);
      ans1.emplace_back(v[i].x+eps,-2000);
      f1 = 0;
    }
    if(v[i].c == 2) {
      ans2.emplace_back(v[i].x-eps,2000 + f2*300);
      ans2.emplace_back(v[i].x-eps,v[i].y-eps);
      ans2.emplace_back(v[i].x+eps,v[i].y-eps);
      ans2.emplace_back(v[i].x+eps,2000);
      f2 = 0;
    }
  }
  cout.setf(ios::fixed);
  cout.precision(5);
  cout << ans1.size() << endl;
  for(auto i : ans1) {
    i = i.rotate(-pend);
    cout << i.x << ' ' << i.y << "\n";
  }

  cout << ans2.size() << endl;
  for(auto i : ans2) {
    i = i.rotate(-pend);
    cout << i.x << ' ' << i.y << '\n';
  }
  return 0;
}
