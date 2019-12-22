#include<bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef long long LL;
string vc[32];
int n;
vector<int> v;
int bt(int b, int must) {
  //cout << (bitset<8>)b << ' ' << (bitset<8>)must << endl;
  if((must & b) != must) return 0; 
  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      int b1 = b & (1<<i);
      int b2 = b & (1<<j);
      if(b1 && b2) {
        if(vc[i][j] == 'D' || vc[j][i] == 'D') {
          int cur = bt(b ^ b1, b2 | must) + bt(b ^ b2, b1 | must) + bt(b^b1^b2, must);
          return cur;
        }
      }
    }
  }
  for(int i : v) if((b & i) == b) return 0;
  v.push_back(b);
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while(cin >> n) {
    v.clear();
    for(int i = 0; i < n; ++i) cin >> vc[i];
    cout << bt((1<<n)-1,0) << endl;
  }
}
