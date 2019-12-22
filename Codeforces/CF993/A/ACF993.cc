#include<bits/stdc++.h>
using namespace std;


#define all(X) X.begin(),X.end()
using vi = vector<int>;
#define sz(X) X.size()
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

typedef Point<int> P;
pair<vi, vi> ulHull(const vector<P>& S) {
	vi Q(sz(S)), U, L;
	iota(all(Q), 0);
	sort(all(Q), [&S](int a, int b){ return S[a] < S[b]; });
	for(auto it: Q) {
#define ADDP(C, cmp) while (sz(C) > 1 && S[C[sz(C)-2]].cross(           \
                                                             S[it], S[C.back()]) cmp 0) C.pop_back(); C.push_back(it);
		ADDP(U, <=); ADDP(L, >=);
	}
	return {U, L};
}

vi convexHull(const vector<P>& S) {
	vi u, l; tie(u, l) = ulHull(S);
	if (sz(S) <= 1) return u;
	if (S[u[0]] == S[u[1]]) return {0};
	l.insert(l.end(), u.rbegin()+1, u.rend()-1);
	return l;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    vector<P> v[2];
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 4; ++j) {
            P p;
            cin >> p.x >> p.y;
            v[i].push_back(p);
        }
    }
    for(int i = -300; i <= 300; ++i) {
        for(int j = -300; j <= 300; ++j) {
            vector<P> n1,n2;
            n1 = v[0], n2 = v[1];
            n1.push_back(P{i,j});
            n2.push_back(P{i,j});
            auto a1 = convexHull(n1);
            auto a2 = convexHull(n2);
            if(a1.size() == 4 && a2.size() == 4) {
                int b[2];
                b[0] = b[1] = 1;
                for(auto k : a1) {
                    if(n1[k] == P{i,j}) b[0] = 0;
                }
                for(auto k : v[0]) {
                    if(k == P{i,j}) b[0] = 1;
                }
                for(auto k : a2) {
                    if(n2[k] == P{i,j}) b[1] = 0;
                }
                for(auto k : v[1]) {
                    if(k == P{i,j}) b[1] = 1;
                }
                if(b[0] && b[1]) return cout << "YES" << endl,0;
            }
        }
    }
    cout << "NO" << endl;
}
