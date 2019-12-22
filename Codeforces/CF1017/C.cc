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
  int mn = 10000000;
  int mnit = 1;
  for(int i = 1; i < n; ++i) {
    if((n+i-1)/i + i < mn) {
      mn = (n+i-1)/i + i;
      mnit = i;
    }
  }
  vector<int> s;
  int cnt = 0;
  int val = 0;
  //assert(mn <= (n+1)/2 + 2);
  //return 0;
  while(val < n) {
    s.push_back(val);
    val += mnit;
    if(cnt++ < n%mnit) --val;
  }
  s.push_back(n);
  /*
  cerr << mn << ' ' << mnit << endl;
  for(int i : s) cout << i << ' ';
  cout << endl;
  */
  for(int i = int(s.size()) - 2; i >= 0; --i) {
    for(int j = 0; j + s[i] < s[i+1]; ++j) {
      cout << j + s[i] + 1<< ' ';
    }
  }
  cout << endl;
  return 0;
}
