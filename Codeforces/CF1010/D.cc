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

struct node {
  string s;
  int v1,v2;
  int x,pos;
}N[1000010];

string ans;
void eval(int u) {
  if(N[u].s == "IN") return;

  if(N[u].s == "NOT") {
    eval(N[u].v1);
    N[u].x = 1 - N[N[u].v1].x;
    return;
  }

  eval(N[u].v1); eval(N[u].v2);
  if(N[u].s == "AND") {
    N[u].x = N[N[u].v1].x && N[N[u].v2].x;
  }

  if(N[u].s == "XOR") {
    N[u].x = N[N[u].v1].x ^ N[N[u].v2].x;
  }

  if(N[u].s == "OR") {
    N[u].x = N[N[u].v1].x || N[N[u].v2].x;
  }
}

void comp(int u) {
  if(N[u].s == "IN") {
    ans[N[u].pos] = (ans[N[u].pos] == '0' ? '1' : '0');
    return;
  }

  if(N[u].s == "NOT") {
    comp(N[u].v1);
  }

  if(N[u].s == "AND") {
    if(N[u].x == 1) {
      comp(N[u].v1);
      comp(N[u].v2);
    }
    if(N[u].x == 0) {
      if(N[N[u].v1].x == 1 && N[N[u].v2].x == 0) comp(N[u].v2);
      if(N[N[u].v1].x == 0 && N[N[u].v2].x == 1) comp(N[u].v1);
    }
  }

  if(N[u].s == "XOR") {
    comp(N[u].v1);
    comp(N[u].v2);
  }

  if(N[u].s == "OR") {
    if(N[u].x == 0) {
      comp(N[u].v1);
      comp(N[u].v2);
    }
    if(N[u].x == 1) {
      if(N[N[u].v1].x == 1 && N[N[u].v2].x == 0) comp(N[u].v1);
      if(N[N[u].v1].x == 0 && N[N[u].v2].x == 1) comp(N[u].v2);
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int cnt  = 0;
  for(int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if(s == "IN") {
      int x;
      cin >> x;
      N[i] = {s, -1, -1, x,cnt++};
    }
    else if(s == "NOT") {
      int x;
      cin >> x;
      --x;
      N[i] = {s, x, -1, -1};
    }
    else {
      int x,y;
      cin >> x >> y;
      --x, --y;
      N[i] = {s, x, y, -1};
    }
  }

  eval(0);
  ans = string(cnt, (N[0].x == 0 ? '0' : '1'));
  comp(0);
  //FOR(i, 0, n) cout << N[i].x << endl;
  cout << ans << endl;
	return 0;
}
