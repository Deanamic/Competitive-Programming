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
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  FOR(i, 0, n) {
    cin >> v[i];
  }
  int g = k;
  FOR(i, 0, n) g = __gcd(g, v[i]%k);
  set<int> can;
  int cur = 0;
  while(!can.count(cur)) {
    can.insert(cur);
    cur += g;
    cur %= k;
  }
  /*
  vector<int> v;
  for(auto i : s) v.push_back(i);
  priority_queue<pair<int,int>> pq;
  pq.push({0, 0});
  set<int> can;
  while(pq.size() && -pq.top().first < k) {
    pair<int,int> p = pq.top();
    cout << p.first << ' ' << p.second << endl;
    pq.pop();
    can.insert(-p.first);
    if(v[p.second] && -(p.first - v[p.second]) < k) pq.push({p.first - v[p.second], p.second});
    for(int i = p.second + 1; i < (int)v.size(); ++i) pq.push({p.first - v[i], i});
  }
  */
  cout << can.size() << endl;
  for(int i : can) cout << i << ' ';
  cout << endl;

	return 0;
}
