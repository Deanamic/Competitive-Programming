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
  string s1,s2;
  cin >> s1 >> s2;
  long long n1 = 0, n0 = 0;
  long long h1 = 0,h0 = 0;
  for(int i = 0; i < n; ++i) {
    if(s2[i] == '0') {
      if(s1[i] == '1') n0++;
      if(s1[i] == '0') n1++;
    }
    if(s1[i] == '1') h1++;
    if(s1[i] == '0') h0++;
  }
  cout << n1 * h1 + n0 * h0 - n1 * n0 << endl;
	return 0;
}
