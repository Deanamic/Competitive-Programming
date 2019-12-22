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
  int n;
  cin >> n;
  int v[n];
  FOR(i, 0, n) cin >> v[i];
  sort(v, v+n);
  ll sum = 0;
  FOR(i, 0, n) sum += 2*v[i];
  int cnt = 0;
  while(sum < 9*n) {
    sum += (10 - 2*v[cnt]);
    cnt++;
  }
  cout << cnt << endl;
	return 0;
}
