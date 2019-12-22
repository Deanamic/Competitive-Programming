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

int v[100010];
int n, f;

bool check(double m) {
  double extra = 0;
  bool full = 0;
  for(int i = 0; i < n; ++i) {
    full = 1;
    extra += (m * f) - v[i];
    if(extra < 0) extra = 0, full = 0;
  }
  return full;
}

bool check2(double m) {
  double extra = 0;
  bool full = 0;
  for(int i = 0; i < n; ++i) {
    full = 1;
    extra += (m * f) - v[i];
    if(extra < 0) full = 0;
    if(!full) return false;
  }
  return 1;
}

int solve() {
  long double sum = 0;
  for(int i = 0; i < n; ++i) {
    cin >> v[i];
    sum += v[i];
  }
  double left = 0, right = 1e9 + 10;
  FOR(i, 0, 500) {
    double m = (left + right)/2;
    if(check(m)) right = m;
    else left = m;
  }
  cout << right << ' ';
  left = 0, right = 1e9 + 10;
  FOR(i, 0, 500) {
    double m = (left + right)/2;
    if(check2(m)) right = m;
    else left = m;
  }
  cout << right << '\n';
  return 0;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(10);
  while(cin >> n >> f) solve();
	return 0;
}
