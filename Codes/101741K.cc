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

const int MaxM = 200005;

struct Trie{
  static const int Alpha = 'z' - 'a' + 1;
  static const int first = 'a';
  int lst = 1;
  struct node{
    int nxt[Alpha] = {}, p = -1;
    char c = '#';
    vector<int> end;
    set<int> endt;
    int SuffixLink = -1;
    int cnt = 0;
  };
	vector<node> V;
  vector<string> v;
	int num;
	stack<int> reversebfs;

	inline int getval(char c) {
		return c - first;
	}

	void CreateSuffixLink() {
		queue<int> q;
		for(q.push(0); q.size(); q.pop()) {
			int pos = q.front();
			reversebfs.push(pos);
      if(!pos || !V[pos].p) V[pos].SuffixLink = 0;
      else {
        int val = getval(V[pos].c);
        int j = V[V[pos].p].SuffixLink;
        V[pos].SuffixLink = V[j].nxt[val];
      }
			for(int i = 0; i < Alpha; ++i) {
				if(V[pos].nxt[i]) q.push(V[pos].nxt[i]);
				else if(!pos || !V[pos].p) {
					V[pos].SuffixLink = 0;
					V[pos].nxt[i] = V[0].nxt[i];
				}
				else {
					int val = getval(V[pos].c);
					int j = V[V[pos].p].SuffixLink;
					V[pos].SuffixLink = V[j].nxt[val];
					V[pos].nxt[i] = V[V[pos].SuffixLink].nxt[i];
				}
			}
		}
	}

	void init(int k) {
    v.resize(k);
    FOR(i, 0, k) cin >> v[i];
		V.resize(MaxM);
		num = k;
		int id = 0;
		for(auto &s : v) {
			int pos = 0;
			for(char &c : s) {
				int val = getval(c);
				if(!V[pos].nxt[val]) {
					V[lst].p = pos;
          V[lst].c = c;
          V[pos].nxt[val] = lst++;
				}
				pos = V[pos].nxt[val];
			}
			V[pos].end.emplace_back(id++);
		}
		CreateSuffixLink();
	}

	vector<int> find(string& word) {
		int pos = 0;
		vector<int> ans(num, 0);
    int tt = 0;
		for(auto c : word) {
			int val = getval(c);
			pos = V[pos].nxt[val];
			V[pos].endt.insert(tt);
      // if(num == 33333 && tt == 73605) cout << V[pos].c << ' ' << V[V[pos].p].c << ' ' << V[V[V[pos].p].p].c <<  endl;
      tt++;
		}
		for(;reversebfs.size();reversebfs.pop()) {
			int	x = reversebfs.top();
      if(V[x].end.size()) {
        int curans = 0;
        int i = sz(v[V[x].end[0]]);
        // if(num == 33333 && v[V[x].end[0]] == "iij") {
        //   cout << x << endl;
        //   for(auto j : V[x].endt) cout << j << ' ';
        //   cout << endl;
        // }
        auto it = V[x].endt.lower_bound(i-1);
        while(it != V[x].endt.end()) {
          curans++;
          it = V[x].endt.lower_bound(*it + i);
        }
        for(int j : V[x].end) ans[j] = curans;
      }
			if(V[x].SuffixLink != -1) {
        if(V[x].endt.size() > V[V[x].SuffixLink].endt.size()) swap(V[V[x].SuffixLink].endt, V[x].endt);
        for(int j : V[x].endt) V[V[x].SuffixLink].endt.insert(j);
      }
		}
		return ans;
	}
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  Trie T;
  T.init(k);
  auto ans = T.find(s);
  // if(k == 33333) {
  //   cout << T.v[5] << endl;
  //   for(int i = 0; i < n - 3; ++i) {
  //     if("iij" == s.substr(i,3)) {
  //       cout << i + 2 << ' ';
  //     }
  //   }
  //   cout << endl;
  // }
  for(int i : ans) cout << i << ' ';
  cout << endl;
	return 0;
}
