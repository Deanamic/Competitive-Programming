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
  int v[2*n];
  FOR(i, 0, 2*n) cin >> v[i];
  int cnt = 0;
  for(int i = 0; i < 2*n; i += 2) {
    int j = i + 1;
    for(; j < 2*n; ++j) {
      if(v[j] == v[i]) break;
    }
    for(; j - 1> i; --j) {
      ++cnt;
      swap(v[j],v[j-1]);
    }
  }
  cout << cnt << endl;
	return 0;
}
