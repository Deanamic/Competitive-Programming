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

bool works(string& P, string& C, string& K) {
  for(int i = 0; i < min(sz(P),sz(K)); ++i) {
    if(((P[i]-'A') + (K[i] - 'A') + 26)%26 != C[i] - 'A') return false;
  }
  for(int i = sz(K); i < sz(P); ++i) {
    if(((P[i]-'A') + (C[i-sz(K)] - 'A') + 26)%26 != C[i] - 'A') return false;
  }
  return true;
}

int solve(int n) {
  vector<pair<string,string> > v(n);
  FOR(i, 0, n) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end(), [](auto& a, auto& b) {
      return a.first.size() > b.first.size();
    });
  FOR(i, 1, 101) {
    string K;
    FOR(j, 0, i) {
      K += 'A' + (v[0].second[j] - v[0].first[j] + 26)%26;
    }
    int good = 1;
    FOR(j, 0, n) {
      good &= works(v[j].first, v[j].second, K);
    }
    if(good) return cout << K << endl, 0;
  }
  cout << "Impossible" << endl;
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  while(cin >> n) {
    if(n == 0) return 0;
    solve(n);
  }
	return 0;
}
