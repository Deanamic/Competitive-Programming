#include <bits/stdc++.h>
using namespace std;

string WINNER[] = {"tokitsukaze", "quailty", "once again"};

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> pos[2];
  for(int i = 0; i < n; ++i) {
    if (s[i] == '0') pos[0].push_back(i);
    else pos[1].push_back(i);
  }
  int leftanchor[2] = {0,0};
  int rightanchor[2] = {0,0};
  if(pos[0].size() <= 1 || pos[1].size() <= 1) return cout << WINNER[0] << endl, 0;
  for(int i = 1; i < (int)pos[0].size(); ++i) {
    if(pos[0][i] - pos[0][0] < k) leftanchor[0] = i;
  }
  for(int i = 1; i < (int)pos[1].size(); ++i) {
    if(pos[1][i] - pos[1][0] < k) leftanchor[1] = i;
  }
  for(int i = (int)pos[0].size() - 1; i >= 0; --i) {
    if(pos[0].back() - pos[0][i] < k) rightanchor[0] = i;
  }
  for(int i = (int)pos[1].size() - 1; i >= 0; --i) {
    if(pos[1].back() - pos[1][i] < k) rightanchor[1] = i;
  }
  leftanchor[0]++;
  leftanchor[1]++;
  rightanchor[0]--;
  rightanchor[1]--;
  if(pos[0].size() == 0 || pos[1].size() == 0) return cout << WINNER[0] << endl, 0;
  if(pos[0].back() - pos[0][0] < k || pos[1].back() - pos[1][0] < k) return cout << WINNER[0] << endl, 0;

  for(int i = 0; i + k <= n; ++i) {
    int l = i, r = i + k;
    int moves[2] = {0,0};
    if(l > pos[0][0]) {
      if(l > pos[0][leftanchor[0]]) moves[0] += 2;
      else moves[0] += 1;
    }
    if(r <= pos[0].back()) {
      if(r <= pos[0][rightanchor[0]]) moves[0] += 2;
      else moves[0] += 1;
    }
    //If he sets to 1
    if(l > pos[1][0]) {
      if(l > pos[1][leftanchor[1]]) moves[1] += 2;
      else moves[1] += 1;
    }
    if(r <= pos[1].back()) {
      if(r <= pos[1][rightanchor[1]]) moves[1] += 2;
      else moves[1] += 1;
    }
    if(moves[0] > 1 || moves[1] > 1) return cout << WINNER[2] << endl, 0;
  }
  cout << WINNER[1] << endl;
}
