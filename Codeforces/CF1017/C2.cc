#include <bits/stdc++.h>
using namespace std;


void go(int l, int r, int ord) {
  if(l + 2 == r) {
    if(ord) cout << l  + 1  << ' ' << l + 1 + 1<< ' ';
    else cout << l + 2  << ' ' << l + 1<< ' ';
    return;
  }
  if(l + 1 == r) {
    cout << l + 1 << ' ';
    return;
  }
  if(l == r) return;

  go((l+r)/2, r, 1 - ord);
  go(l, (l+r)/2, 1 - ord);
}

int main() {
  int n;
  cin >> n;
  go(0, n , 0);
  cout << endl;
}
