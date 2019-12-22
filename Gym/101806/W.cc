#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll oo = 0x3f3f3f3f3f3f3f3fLL;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define has(c, e) ((c).find(e) != (c).end())
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()

struct SF {
  pair<int, int> ord;
  int id;
  bool operator<(const SF& s) const { return ord < s.ord; }
};
// This must be filled before calling compute_suffix_array():
int N;
string S;
// This is filled by compute_suffix_array():
vector<SF> A;
vector<vector<int> > B;
int step;

int lcp(int x, int y) {
  if (x == y) return N - x;
  int res = 0;
  for (int i = step - 1; i >= 0 and x < N and y < N; --i)
    if (B[i][x] == B[i][y]) { x += 1<<i; y += 1<<i; res += 1<<i; }
  return res;
}

const int MAXN = 1000005;

SF L2[MAXN];
int pos[MAXN + 2], times[MAXN + 2];
void raddixSort() {
  int k = max(N, 256);
  for (int i = 0; i < k + 2; ++i) times[i] = 0;
  for (int i = 0; i < N; ++i)
    times[A[i].ord.second + 1]++;
  pos[0] = 0;
  for (int i = 1; i < k + 2; ++i)
    pos[i] = pos[i - 1] + times[i - 1];
  for (int i = 0; i < N; ++i)
    L2[pos[A[i].ord.second + 1]++] = A[i];

  for (int i = 0; i < k + 2; ++i)
    times[i] = 0;
  for (int i = 0; i < N; ++i)
    times[L2[i].ord.first + 1]++;
  pos[0] = 0;
  for (int i = 1; i < k + 2; ++i)
    pos[i] = pos[i - 1] + times[i - 1];
  for (int i = 0; i < N; ++i)
    A[pos[L2[i].ord.first + 1]++] = L2[i];
}

void compute_suffix_array() {
  A.resize(N); B.resize(1); B[0].resize(N);
  for (int i = 0; i < N; ++i) B[0][i] = S[i];
  step = 1;
  for (int b = 0, pw = 1; b < N; ++step, pw<<=1) {
    for (int i = 0; i < N; ++i) {
      A[i].ord.first = B[step - 1][i];
      A[i].ord.second = i + pw < N ? B[step - 1][i + pw] : -1;
      A[i].id = i;
    }
    sort(A.begin(), A.end()); // raddixSort();
    B.resize(step + 1); B[step].resize(N);
    b = B[step][A[0].id] = 1;
    for (int i = 1; i < N; ++i) {
      if (A[i - 1] < A[i]) ++b;
      B[step][A[i].id] = b;
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  cin >> S;
  compute_suffix_array();

  vector<int> v;
  char ref = S[0];
  int cnt = 0;
  FOR(i, 0, N) {
    if(ref == S[i]) ++cnt;
    else {
      v.push_back(cnt);
      cnt = 1;
      ref = S[i];
    }
  }
  v.push_back(cnt);
  if(v.size() == 1) return cout << "0 0" << endl, 0;
  if(S[0] == '0') {
    cout << "0 ";
    int num = 0;
    int mx = 0;
    int curans = 0;
    for(int i = 0; i < sz(v); ++i) {
      if(i&1) {
        if(v[i] > mx) {
          curans = num;
          mx = v[i];
        }
        else if(v[i] == mx) {
          if(B[step-1][num] > B[step-1][curans]) {
            curans = num;
            mx = v[i];
          }
        }
      }
      num += v[i];
    }
    cout << curans << endl;;
  }
  else {
    cout << v[0] << " ";
    int num = 0;
    int mx = 0;
    int curans = 0;
    for(int i = 1; i < sz(v); ++i) {
      if((i&1) == 0 && i > 1) {
        if(v[i] > mx) {
          curans = num;
          mx = v[i];
        }
        else if(v[i] == mx) {
          if(B[step-1][num + v[0]] > B[step-1][v[0] + curans]) {
            curans = num;
            mx = v[i];
          }
        }
      }
      num += v[i];
    }
    cout << curans << endl;
  }
	return 0;
}
