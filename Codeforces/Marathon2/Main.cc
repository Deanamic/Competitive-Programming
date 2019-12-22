#include <bits/stdc++.h>
using namespace std;

int N, S, C, H, U;
string stripe, bottles;
set<int> colors[10];
int chamaleon[10];

inline void moveCham(int id, int col) {
  int curPos = chamaleon[id];
  colors[stripe[curPos]-'A'].insert(curPos);
  int nwPos = *upper_bound(colors[col].begin(), colors[col].end(), curPos%N);
  nwPos = (curPos/N) * N + nwPos;
  colors[stripe[nwPos]-'A'].erase(nwPos);
  chamaleon[id] = nwPos;
  cout << id << ' ' << char(col + 'A') << '\n';
}

inline int Value(int id, int col) {
  int curPos = chamaleon[id];
  colors[stripe[curPos]-'A'].insert(curPos);
  int nwPos = *upper_bound(colors[col].begin(), colors[col].end(), curPos%N);
  nwPos = (curPos/N) * N + nwPos;
  return nwPos - curPos;
}
int main() {
  ios::sync_with_stdio(0);

  cin >> N >> S >> C >> H >> U;
  cin >> stripe >> bottles;

  for(int i = 0; i < 2*N; ++i) {
    char c = stripe[i%N];
    colors[c-'A'].insert(i);
  }
  iota(chamaleon, chamaleon + 10, 0);
  for(int i = 0; i < 10; ++i) colors[stripe[i]-'A'].erase(i);
  //int it = 0;
  for(char c : bottles) {
    //cerr << it++ << endl;
    int curBest = 0;
    int Best = 0;
    for(int i = 0; i < 10; ++i) {
      int cur = Value(i, c - 'A');
      if(cur > Best) Best = cur,curBest = i;
    }
    moveCham(curBest, c - 'A');
  }
}
