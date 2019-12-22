#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n, k;
  long long v;
  cin >> n >> k >> v;
  --v;
  string s[n];
  for(int i = 0; i < n; ++i) cin >> s[i];
  vector<int> ans;
  for(int i = 0; i < k; ++i) {
    ans.push_back((i + v*k) % n);
  }
  sort(ans.begin(), ans.end());
  for(int i : ans) cout << s[i] << ' ';
  cout << endl;
}
int main() {
  int T;
  cin >> T;
  for(int I = 0; I < T; ++I) {
    cout << "Case #" << I + 1 << ": ";
    solve();
  }
}
