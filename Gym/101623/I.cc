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

struct cosa{
  int x, y;
  int ind;
  int trip;
  bool operator <(const auto a) const {
    return x + y < a.x + a.y;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, c;
  cin >> n >> c;
  vector<cosa> v(n);
  FOR(i, 0, n) {
    cin >> v[i].x >> v[i].y;
    v[i].ind = i;
    v[i].x = c - max(v[i].y, v[i].x);
  }
  sort(v.begin(), v.end());
  FOR(i, 0, n) v[i].trip = i;
  priority_queue<pair<int,int>> pq;
  pq.push({0,-1});
  ll h = 0;
  FOR(i, 0, n) {
    if(v[i].x >= h) {
      h += v[i].y;
      pq.push({v[i].y, i});
    }
    else {
      if(v[i].y < pq.top().first) {
        h -= pq.top().first;
        h += v[i].y;
        pq.pop();
        pq.push({v[i].y, i});
      }
    }
  }
  vector<cosa> ans;
  while(pq.size()) {
    auto a = pq.top();
    pq.pop();
    if(a.second != -1) ans.push_back(v[a.second]);
  }
  sort(ans.begin(), ans.end(), [](auto a, auto b) {
      return a.trip < b.trip;
    });
  cout << ans.size() << endl;
  FOR(i, 0, sz(ans)) {
    cout << ans[i].ind + 1<< ' ';
  }
  cout << endl;
	return 0;
}
