#include <bits/stdc++.h>
using namespace std;

int N, S, C, H, U;
string stripe, bottles;
set<int> colors[10];
int chamaleon[10];

inline void moveCham(int id, int col) {
  cout << id << ' ' << char(col + 'A') << '\n';
}

int main() {
  ios::sync_with_stdio(0);

  cin >> N >> S >> C >> H >> U;
  cin >> stripe >> bottles;

  for(int i = 0; i < S; ++i) {
    char c = bottles[i];
    int cur = rand()%10;
    moveCham(cur, c - 'A');
  }
}
