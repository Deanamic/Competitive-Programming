#include <bits/stdc++.h>

using namespace std;

struct pers {
  long long b, f, d;
};

bool comp(pers& a, pers& b) {
  if (a.b == b.b) return a.f < b.f;
  return a.b < b.b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <pers>v(n);
  for (int i = 0; i < n; ++i) cin >> v[i].b >> v[i].f >> v[i].d;
  sort(v.begin(), v.end(), comp);
  vector <pers>y;
  y.push_back(v[0]);
  for (int i = 1; i < n; ++i) {
    if (y[y.size()-1].b == v[i].b && y[y.size()-1].f == v[i].f) y[y.size()-1].d += v[i].d;
    else y.push_back(v[i]);
  }
  map <int, long long>m;
  map <int, long long>m3;
  m[0] = 0;
  map <int, long long>::iterator it;
  long long ans = 0;
  long long cur = 0;
  for (int i = 0; i < (int)y.size(); ++i) {
    if (i > 0 and y[i].b > y[i-1].b) {
      for (it = m3.begin(); it != m3.end(); ++it) {
        if(it->second < (--m.lower_bound(it->first))->second) continue;
        if (m.find(it->first) == m.end()) m[it->first] = it->second;
        else m[it->first] = max(it->second, m[it->first]);
        auto del = m.lower_bound(it->first + 1);
        while(del->second < it->second) del = m.erase(del);
      }
      m3.clear();
      cur = 0;
      //for(auto it : m) cout << it.first << ' ' << it.second << endl;
    }
    it = m.lower_bound(y[i].f);
    --it;
    long long c = it->second;
    cur = max(cur, c + y[i].d);
    m3[y[i].f] = cur;
    ans = max(ans, cur);
  }
  cout << ans << endl;
}
