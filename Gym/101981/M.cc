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

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

void manacher(int n, string str, vector<int>& r) {
	r[0] = 0;
	int p = 0;
	FOR(i, 1, 2*n-1) {
		r[i] = (p/2 + r[p] >= (i+1)/2) ? min(r[2*p - i], p/2 + r[p] - i/2) : 0;
		while (i/2 + r[i] + 1 < n && (i+1)/2 - r[i] - 1 >= 0
           && str[i/2 + r[i] + 1] == str[(i+1)/2 - r[i] - 1]) r[i]++;
		if (i/2 + r[i] > p/2 + r[p]) p = i;
	}
}

vector<int> Z(string &s) {
  int n = s.size();
  int L, R;
  L = R = 0;
  vector<int> Za(n, 0);
  for (int i = 1; i < n; ++i){
    if (i < R) Za[i] = min(Za[i-L], R-i);
    else Za[i] = 0;
    while (Za[i] + i < n and s[Za[i]] == s[i+Za[i]]) ++Za[i];
    if (i+Za[i] > R){
      L = i;
      R = i + Za[i];
    }
  }
  return Za;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s,t;
  cin >> s >> t;
  int n = s.size();
  reverse(s.begin(), s.end());
  string p = t + '$' + s;
  vector<int> ZZ = Z(p);

  vector<int> r(2*n - 1,0);
  manacher(n, s, r);
  FT fen(n+10);
  FOR(i, 0, sz(r)) {
    if(i%2) {
      int pos = i/2;
      fen.update(pos+1, 1);
      fen.update(pos + r[i] + 1, -1);
    }else {
      int pos = i/2;
      fen.update(pos + r[i] + 1, -1);
      fen.update(pos, 1);
    }
  }
  //FOR(i, 0, n) cout << ZZ[i] << ' ';
  //cout << endl;
  //FOR(i, 0, n+1) cout << fen.query(i) << ' ';
  //cout << endl;
  ll ans = 0;
  for(int i = 0; i < s.size(); ++i) {
    int x = ZZ[i+t.size()+1];
    ans += x*fen.query(i);
    //cout << x << ' ' << fen.query(i) << endl;
  }
  cout << ans <<endl;
	return 0;
}
