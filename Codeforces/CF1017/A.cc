#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define has(c, e) ((c).find(e) != (c).end())
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int cnt = 1, sum = 0;
  int x;
  for(int i = 0; i < 4; ++i) {
    cin >> x;
    sum += x;
  }
  for(int i = 1; i < n; ++i) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a+b+c+d > sum) ++cnt;
  }
  cout << cnt << endl;
	return 0;
}
