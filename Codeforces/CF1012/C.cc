#include <bits/stdc++.h>
using namespace std;

inline int cost(int a, int b) {
  return max(0, b - a + 1);
}

int main() {
  int n;
  cin >> n;
  int a[n+2];
  for(int i = 1; i < n + 1; ++i) cin >> a[i];
  a[0] = a[n+1] = -10000000;
  int cur[n+2][n][2];
  memset(cur, 0x3f, sizeof(cur));
  cur[0][0][0] = cur[0][0][1] = 0;
  for(int i = 1; i <= n + 1; ++i) {
    for(int j = 0; j <= (i+1)/2; ++j) {
      cur[i][j][0] = min(cur[i-1][j][0], cur[i-1][j][1]);
      if(j) {
        if(i > 1) cur[i][j][1] = min(cur[i-2][j-1][0] + cost(a[i], a[i-1]), cur[i-2][j-1][1] + cost(a[i], (j > 1 ? min(a[i-2] - 1, a[i-1]) : a[i-1]))) + cost(a[i], a[i+1]);
        else cur[i][j][1] = min(cur[i][j][1],  cost(a[i], a[i-1]) + cost(a[i], a[i+1]));
      }
    }
  }
  for(int i = 1; i <= (n+1)/2; ++i) cout << cur[n+1][i][0] << ' ';
  cout << endl;
}
