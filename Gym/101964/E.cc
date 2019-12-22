#include <bits/stdc++.h>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll oo = 0x3f3f3f3f3f3f3f3fLL;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define has(c, e) ((c).find(e) != (c).end())
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()

struct fish{
  int x, y, id;
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, l;
  cin >> n >> m >> l;
  int llm = 1e9;
  vector<fish> v(n);
  FOR(i, 0, n) {
    int x, y;
    cin >> x >> y;
    v[i] = {x,y,i};
  }
  vector<pair<int,int>> fm(m);
  int ans[m];
  FOR(i, 0, m) {
    int x;
    cin >> x;
    fm[i] = {x,i};
  }
  sort(fm.begin(), fm.end());
  ordered_set<pair<int,int>> lft, rgh;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq, pq2;

  sort(v.begin(), v.end(), [](auto& a, auto& b) {
      if(a.x != b.x) return a.x < b.x;
      return a.y < b.y;
    });


  for(int i = 0; i < n; ++i) {
    pq.push({v[i].x + v[i].y - l, i});
  }
  int it = 0;
  int ansl = 0, ansr = 0;
  for(int i = 0; i < m; ++i) {
    while(it < sz(v) && v[it].x < fm[i].first) {
      if(i && v[it].x + v[it].y - l <= fm[i-1].first) --ansl;
      ++it;
    }
    while(sz(pq) && pq.top().first <= fm[i].first) {
      if(v[pq.top().second].x >= fm[i].first) ++ansl;
      pq.pop();
    }
    ans[fm[i].second] = ansl;
  }


  reverse(fm.begin(), fm.end());
  for(int i = 0; i < m; ++i) fm[i].first = llm - fm[i].first;
  for(int i = 0; i < n; ++i) v[i].x = llm - v[i].x;
  reverse(v.begin(), v.end());
  it = 0;
  for(int i = 0; i < n; ++i) {
    pq2.push({v[i].x + v[i].y - l, i});
  }

  for(int i = 0; i < m; ++i) {
    while(it < sz(v) && v[it].x <= fm[i].first) {
      if(i && v[it].x + v[it].y - l <= fm[i-1].first) --ansr;
      ++it;
    }
    while(sz(pq2) && pq2.top().first <= fm[i].first) {
      if(v[pq2.top().second].x > fm[i].first) ++ansr;
      pq2.pop();
    }
    //cout << ansr << endl;
    ans[fm[i].second] += ansr;
  }
  for(int i = 0; i < m; ++i) cout << ans[i] << '\n';
	return 0;
}
