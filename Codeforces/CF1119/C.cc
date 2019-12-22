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
  int n, m;
  cin >> n >> m;
  vector<vi> A(n, vi(m)), B(n, vi(m));
  FOR(i, 0, n) FOR(j, 0, m) cin >> A[i][j];
  FOR(i, 0, n) FOR(j, 0, m) cin >> B[i][j];
  vector<int> v1,v2;
  vector<int> bi(n,0), bj(m,0);
  FOR(i, 0, n) FOR(j, 0, m) {
    if(A[i][j] != B[i][j]) {
      v1.push_back(i);
      v2.push_back(j);
      bi[i]++;
      bj[j]++;
    }
  }
  int can = 1;
  FOR(i, 0, n) if(bi[i]&1)can = 0;
  FOR(j, 0, m) if(bj[j]&1)can = 0;
  cout << (can ? "Yes" : "No") << endl;
  return 0;
}
