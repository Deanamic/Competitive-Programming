#include <bits/stdc++.h>
using namespace std;

long long g;
long long n;
vector<pair<long long, long long>> v;
long long p[1024][1024] = {};
long long dp[1024][1024] = {};

bool can(long long days) {
  dp[0][0] = v[0].second;
  dp[0][1] = v[0].first * days;
  if(p[0][min(n,days)] >= g) return true;
  if(dp[0][0] + p[1][min(n,days) - 1] >= g) return true;
  if(dp[0][1] + p[1][min(n,days) - 1] >= g) return true;
  for(int i = 1; i < min(days,n); ++i) {
    for(int j = 0; j <= i + 1; ++j) {
      dp[i][j] = dp[i-1][j] + v[i].second;
      if(j) dp[i][j] = max(dp[i-1][j-1] + (v[i].first * (days + 1 - j)), dp[i][j]);
      if(dp[i][j] + p[i+1][min(days,n) - (i+1)] >= g) return true;
    }
  }
  return false;
}

void solve() {
  v.resize(n);
  for(int i = 0; i < n; ++i) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end(), greater<pair<long long,long long>>());
  memset(p, 0, sizeof(p));
  p[n-1][1] = v[n-1].second;
  for(int j = n-2; j >= 0; --j) {
    for(int i = 1; i + j <= n; ++i) {
      p[j][i] = max(p[j+1][i], p[j+1][i-1] + v[j].second);
    }
  }
  long long l = 0, r = 1e17/v[0].first;
  while(l + 1 < r) {
    long long m = (l+r)>>1;
    if(can(m)) r = m;
    else l = m;
  }
  cout << r << endl;
}

int main() {
  while(cin >> g >> n) solve();
}
