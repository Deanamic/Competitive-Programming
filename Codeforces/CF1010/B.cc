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

int n, m;
int curans;
void asky(int y) {
  cout << y << endl;
}

void readans(){
  cin >> curans;
  if(curans == 0) exit(0);
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> m >> n;
  int cycle[n];
  for(int i = 0; i < n; ++i) {
    cout << 1 << endl;
    readans();
    cycle[i] = curans;
  }

  int l = 0, r = m+1;
  int it = 0;
  while(l + 1 < r) {
    int mm = (l+r)>>1;
    asky(mm);
    readans();
    if(curans * cycle[it%n] > 0) l = mm;
    else r = mm;
    it++;
  }
	return 0;
}
