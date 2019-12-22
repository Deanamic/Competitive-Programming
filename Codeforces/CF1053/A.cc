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
  ll n, m, k;
  cin >> n >> m >> k;
  m<<=1
  if((n*m)%k) return cout << "NO" << endl, 0;
  ll obj = (n*m*2)/k;
  vector<int> v1(1,1),v2(1,1);
  for(int i = 2; i * i <= n; ++i) {
    if(n%i == 0) v1.push_back(i), v1.push_back(n/i);
  }
  if(v1.empty()) v1.push_back(n);
  for(int i = 2; i * i <= m; ++i) {
    if(m%i == 0) v1.push_back(i), v1.push_back(n/i);
  }
  if(v2.empty()) v2.push_back(m);

  for(ll i = 1; i * i <= obj; ++i) {
  }
  cout << "NO" << endl;
	return 0;
}
