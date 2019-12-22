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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, d, k;
  cin >> n >> d >> k;
  vector<pair<int,string>> v(n);
  FOR(i, 0, n) cin >> v[i].second >> v[i].first;
  sort(v.begin(), v.end(), [](auto p1, auto p2) {
      return p1.first > p2.first;
    });
  ll save = 0;
  FOR(i, 0, k) {
    save += v[i].first;
  }
  string s = ", YOU ARE FIRED!";
  if(save >= d) {
    cout << k << endl;
    FOR(i, 0, k) {
      cout << v[i].second << s << '\n';
    }
  }
  else cout << "impossible" << endl;
	return 0;
}
