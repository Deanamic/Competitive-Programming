#include <bits/stdc++.h>
using namespace std;

int main () {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      ans += ((i + j) & 1 ? 1 : -1) * (c == '-' ? 2 : 1);
    }
  }
  cout << "YN"[ans!=0] << endl;
}
