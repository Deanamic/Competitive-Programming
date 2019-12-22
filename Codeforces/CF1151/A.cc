#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()
#define debug(x) cerr << #x << ": " << x << endl;

int calc(string s) {
  int ans = 0;
  ans += min(abs(s[0] - 'A'), 'Z' - s[0] + 1);
  ans += min(abs(s[1] - 'C'), 'Z' - s[1] + 'C' - 'A' + 1);
  ans += min(abs(s[2] - 'T'), 'Z' - s[2] + 'T' - 'A' + 1);
  ans += min(abs(s[3] - 'G'), 'Z' - s[3] + 'G' - 'A' + 1);
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 10000000;
  for(int i = 0; i < n-3; ++i) {
    ans = min(ans,calc(s.substr(i, 4)));
  }
  cout << ans << endl;
}
