#include <bits/stdc++.h>
using namespace std;

vector<int> adj[250010];

struct Node{
  int u, v;
  long long w;
  int x;
};

vector<Node> E;
long long dp[2][250010];
//dp[0] connected to parent, dp[1] not connected to parent
long long ans = 0;
using ll = long long;
vector<vector<int>> fix;

struct topk{
  int k;
  priority_queue<long long> A,B;
  void push (long long x)	{
    A.push(x);
  }
  void del (long long x)	{
    B.push(x);
  }
  long long top ()	{
    while (!B.empty()&&A.top()==B.top()) {
      A.pop();
      B.pop();
      return A.top();
    }
  }
  void pop ()	{
    top();
    A.pop();
  }
  long long size() {
    return A.size() - B.size();
  }
  topk(int kk) : k(kk){}
};

void dfs(int u, int p, int x, ll w = 0) {
  vector<pair<long long,int>> cost;
  long long ans = 0;
  for(auto i : adj[u]) {
    int v = u ^ E[i].x;
    if(v != p){
      dfs(v, u, x);
      cost.emplace_back(dp[1][v] - dp[0][v], i, E[i].w);
      ans += dp[0][v];
    }
  }
  sort(cost.begin(), cost.end());
  dp[1][u] = w;
  dp[0][u] = 0;
  for(int i = 0; i < (int)cost.size(); ++i) {
    int val = cost[i].first;
    if(val < 0 || i + 1 < (int(cost.size()) - (x-1))) dp[1][u] += val;
    if(val < 0 || i < (int(cost.size()) - (x-1))) dp[0][u] += val;
  }
  dp[1][u] = min(dp[1][u], dp[0][u]);
}

int main() {
  int n;
  cin >> n;
  fix.resize(n);
  for(int i = 0; i < n-1; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    --a,--b;
    adj[a].push_back(i);
    adj[b].push_back(i);
    E.push_back({a,b,c,a^b});
    ans += c;
  }
  for(int i = 0; i < n; ++i) {
    auto &v = adj[i];
    sort(v.begin(), v.end(), [](auto a, auto b) {
                               return adj[b].size() < adj[a].size();
                             });
    fix[v.size()].push_back(i);
  }
  cout << ans << ' ';
  for(int i = 1; i < n; ++i) {
    ans = 0;
    dfs(0, -1, i);
    cout << ans << ' ';
  }
  cout << endl;
}
