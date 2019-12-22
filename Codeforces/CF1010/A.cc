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

double a[1010], b[1010];
int n, K;

bool can(long double m) {
  for(int i = 0; i < n; ++i) {
    m -= (m+K)/a[i];
    m -= (m+K)/b[(i+1)%n];
  }
  return m >= 0;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout.precision(14); cout.setf(ios::fixed);

  cin >> n >> K;


  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < n; ++i) cin >> b[i];

  long double l = 0, r = 5e9;
  for(int i = 0; i < 500; ++i) {
    long double m = (l+r)/2;
    if(can(m)) r = m;
    else l = m;
  }
  if(r > 2e9) return cout << -1 << endl, 0;
  cout << r << endl;
	return 0;
}
