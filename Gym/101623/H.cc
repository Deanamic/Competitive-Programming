#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll oo = 0x3f3f3f3f3f3f3f3fLL;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define has(c, e) ((c).find(e) != (c).end())
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
	int t;
    cin >> t;
    while (t--) {
        ll a, b, c, n;
        cin >> a >> b >> c >> n;
        ll ans = 0;
        if (n < 200) {
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; i+j <= n; ++j) {
                    ll x = a+n-i-j, y = b+i, z = c+j;
                    ans = max(ans, x*x+y*y+z*z+min(x, min(y, z))*7);
                }
            }
        }
        if (a < b) swap(a, b);
        if (b < c) swap(b, c);
        if (a < b) swap(a, b);
        ans = max(ans, (a+n)*(a+n)+b*b+c*c+min(a, min(b, c))*7);
        cout << ans << endl;
    }
    return 0;
}
