#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("O3")
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll oo = 0x3f3f3f3f3f3f3f3fLL;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define has(c, e) ((c).find(e) != (c).end())
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()

unordered_set<ll> s[12];

int lg(ll x) {
  if(x < 10) return 1;
  return 1 + lg(x/10);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string S;
  cin >> S;
  string ans = S;

  //generate things
  for(int i = 2; i <= 100000; ++i) {
    ll cur = i;
    for(int j = 2; cur <= 10000000000000; ++j) {
      cur *= i;
      if(lg(i) + lg(j) + 1 < lg(cur)) for(int k = lg(i) + 1 + lg(j); k <= 11; ++k) s[k].insert(cur);
    }
  }

  if(sz(S) <= 3) return cout << ans << endl, 0;
  ll x = stoll(S);
  if(s[3].count(x)) {
    for(int i = 2; i <= 9; ++i) {
      ll cur = i;
      for(int j = 2; j <= 9; ++j) {
        cur *= i;
        if(cur == x) return cout << i << '^' << j << endl, 0;
      }
    }
  }

  if(sz(S) <= 4) return cout << ans << endl, 0;
  if(s[4].count(x)) {
    for(int i = 2; i <= 99; ++i) {
      ll cur = i;
      for(int j = 2; j <= 99 && cur <= x && lg(i) + lg(j) <= 3; ++j) {
        cur *= i;
        if(cur == x) return cout << i << '^' << j << endl, 0;
      }
    }
  }

  if(sz(S) <= 5) return cout << ans << endl, 0;

  if(s[sz(ans) - 1].count(x)) {
    for(int i = 2; i <= 100000; ++i) {
      ll cur = i;
      for(int j = 2; cur <= x && lg(i) + lg(j) < sz(ans) - 1; ++j) {
        cur *= i;
        if(cur == x) ans = to_string(i) +"^" + to_string(j);
      }
    }
  }
  for(int I = 1; I <= 999; ++I) {
    ll y = x - I;
    if(sz(ans) - 2 - lg(I) >= 0) {
      if(y > 0 && s[sz(ans) - 1 - lg(I)].count(y)) {
        for(int i = 2; i <= 100000; ++i) {
          ll cur = i;
          for(int j = 2; cur <= y && lg(i) + lg(j) + 2 + lg(I) < sz(ans); ++j) {
            cur *= i;
            if(cur == y) ans = to_string(i) + "^" + to_string(j) + "+" + to_string(I);
          }
        }
      }
      if(I > 1 && x%I == 0) {
        y = x/I;
        if(s[sz(ans) - 1 - 1 - lg(I)].count(y)) {
          for(int i = 2; i <= 100000; ++i) {
            ll cur = i;
            for(int j = 2; cur <= y && lg(i) + lg(j) + 2 + lg(I) < sz(ans); ++j) {
              cur *= i;
              if(cur == y) ans = to_string(I) + "*" + to_string(i) + "^" + to_string(j);
            }
          }
        }
      }
    }
  }
  for(int J = 2; J <= 999; ++J) {
    for(int I = 1; I <= 999; ++I) {
      ll y = x - I;
      if(y % J == 0 && sz(ans) - 3 - lg(I) - lg(J) >= 0) {
        y = y/J;
        if(s[sz(ans) - 3 - lg(I) - lg(J)].count(y)) {
          for(int i = 2; i <= 100000; ++i) {
            ll cur = i;
            for(int j = 2; cur <= y && lg(i) + lg(j) + 3 + lg(I)+ lg(J) < sz(ans); ++j) {
              cur *= i;
              if(cur == y) ans = to_string(J) + "*" + to_string(i) + "^" + to_string(j) + "+" + to_string(I);
            }
          }
        }
      }
    }
  }

  for(int I : s[3]) {
    if(x%I  == 0 && sz(ans) > 4 && s[sz(ans) - 4].count(x/I)) {
      int x1,x2;
      int y1,y2;
      x1 = x2 = y1 = y2 = -1;
      for(int i = 2; x1 == -1 && i <= 9; ++i) {
        ll cur = i;
        for(int j = 2; x1 == -1 && j <= 9; ++j) {
          cur*=i;
          if(cur == I) {
            x1 = i;
            x2 = j;
          }
        }
      }
      for(int i = 2; y1 == -1 && i <= 99; ++i) {
        ll cur = i;
        for(int j = 2; y1 == -1 && j <= 99; ++j) {
          cur*=i;
          if(cur == x/I) {
            y1 = i;
            y2 = j;
          }
        }
      }
      if(lg(x1) + lg(x2) + lg(y1) + lg(y2) + 3 < sz(ans)) ans = to_string(x1) + "^" + to_string(x2) + "*" +  to_string(y1) + "^" +  to_string(y2);
    }
  }

  if(sz(ans) > 7) {
    for(int I : s[3]) {
      if(x%I  == 0 && sz(ans) > 4 && s[sz(ans) - 4].count(x/I)) {
        int x1,x2;
        int y1,y2;
        x1 = x2 = y1 = y2 = -1;
        for(int i = 2; x1 == -1 && i <= 9; ++i) {
          ll cur = i;
          for(int j = 2; x1 == -1 && j <= 9; ++j) {
            cur*=i;
            if(cur == I) {
              x1 = i;
              x2 = j;
            }
          }
        }
        for(int i = 2; y1 == -1 && i <= 99; ++i) {
          ll cur = i;
          for(int j = 2; y1 == -1 && j <= 99; ++j) {
            cur*=i;
            if(cur == x/I) {
              y1 = i;
              y2 = j;
            }
          }
        }
        if(lg(x1) + lg(x2) + lg(y1) + lg(y2) + 3 < sz(ans)) ans = to_string(x1) + "^" + to_string(x2) + "*" +  to_string(y1) + "^" +  to_string(y2);
      }
    }
  }

  return cout << ans << endl, 0;
  return 0;
}
