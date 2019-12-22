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

vector<ll> vl, vr;

struct SegmentTree{
  vector<ll> Seg;
  vector<int> Ind;
	int n;

	void build(int m){
		n = m;
    Seg = vector<ll> (4*n, -oo);
    Ind = vector<int> (4*n, 0);
	}

	void update(int p, ll new_value){
		update(p, new_value, 1, 0, n);
	}
	void update(int p, ll new_value, int id, int left, int right){
		if(left + 1 >= right){
      Ind[id] = left;
			Seg[id] = new_value;
			return;
		}
		int mid = (left+right)/2;
		if(p < mid) update(p, new_value, 2*id, left, mid);
		else update(p, new_value, 2*id + 1, mid, right);

		Seg[id] = max(Seg[id*2], Seg[id*2 + 1]);

    if(Seg[id*2] > Seg[id*2 + 1]) Ind[id] = Ind[id*2];
    else if(Seg[id*2] == Seg[id*2+1]) {
      if(vr[Ind[id*2]] < vr[Ind[id*2 + 1]]) {
        Ind[id] = Ind[id*2];
      }
      else Ind[id] = Ind[id*2 + 1];
    }
    else Ind[id] = Ind[id*2 + 1];
	}
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  SegmentTree Li, Ri;
  priority_queue<pair<ll,int>> pq;
  Li.build(n);
  Ri.build(n);
  vector<int> used(n,0);
  ll cur = oo;
  FOR(i, 0, n) {
    ll l, r;
    cin >> l >> r;
    pq.push({l+r, i});
    vl.push_back(l);
    vr.push_back(r);
    Ri.update(i,-oo);
    Li.update(i, l);
  }
  FOR(i, 0, n) {
    ll curmax = -1;
    int argmax = 0;
    FOR(j, 0, n) {
      if(!used[j]) {
        ll curr = min(vl[j], cur - vr[j]);
      }
    }
    used[argmax] = 1;
    cur = curmax;
    cout << cur << ' ' << argmax << endl;
  }
  return 0;
  FOR(i, 0, n) {
    cout << cur << ' ';
    while(pq.size() && pq.top().first >= cur) {
      auto t = pq.top();
      pq.pop();
      Li.update(t.second, -oo);
      if(used[t.second] == 0) Ri.update(t.second, -vr[t.second]);
    }
    ll lft = Li.Seg[1];
    ll rgt = cur + Ri.Seg[1];
    if(lft < 0 && rgt < 0) return cout << i << endl, 0;
    if(lft >= rgt) {
      cout << "Li: " << Li.Ind[1] << ' ' << lft << ' ' << cur -lft<< endl;
      used[Li.Ind[1]] = 1;
      cur = lft;
      Li.update(Li.Ind[1], -oo);
    }
    else {
      cout << "Ri: " << Ri.Ind[1] << ' ' << rgt << ' ' << cur - rgt << endl;
      cur = rgt;
      Ri.update(Ri.Ind[1], -oo);
    }
  }
  cout << n << endl;
	return 0;
}
