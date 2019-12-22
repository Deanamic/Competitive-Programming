#include <bits/stdc++.h>
using namespace std;

//subcaso 3
int dist(int a, int b) {
    return min(abs(b-a), abs(a-b));
}

int main() {
    int x, y;
    while(cin >> x >> y) {
        int Q;
        cin >> Q;
        while(Q--) {
            int a,b;
            cin >> a >> b;
            int ans = min(abs(x - a) + abs(y - b), dist(a,b) + dist(x,y));
            cout << ans;
            if(!Q) cout << endl;
            else cout << ' ';
        }
    }
}
