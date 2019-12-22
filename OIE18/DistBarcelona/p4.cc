#include <bits/stdc++.h>
using namespace std;

//subcaso 4
const int oo = 0x3fffffff;

int d(int a, int b, int c, int d) {
    return abs(a - c) + abs(b - d);
}

int dist(int a, int b) {
    return abs(b-a);
}


int main() {
    int x, y;
    while(cin >> x >> y) {
        int px[2], py[2];
        px[0] = x - x%10;
        px[1] = x - x%10 + 10;

        py[0] = y - y%10;
        py[1] = y - y%10 + 10;
        int Q;
        cin >> Q;
        while(Q--) {
            int a,b;
            cin >> a >> b;
            int cx[2], cy[2];
            cx[0] = a - a%10;
            cx[1] = a - a%10 + 10;

            cy[0] = b - b%10;
            cy[1] = b - b%10 + 10;
            int ans = oo;
            if(a % 10 == 0 && a == x) ans = abs(b-y);
            if(b % 10 == 0 && b == y) ans = abs(a-x);
            for(int I = 0; I < 0xf; ++I) {
                bool i = I&1, j = I&2, k = I&4, l = I&8;
                ans = min(dist(cx[i], cy[j]) + dist(px[k],py[l]) + d(a,b,cx[i],cy[j]) + d(x, y, px[k], py[l]), ans);
                ans = min(d(cx[i], cy[j], px[k], py[l]) + d(a,b,cx[i],cy[j]) + d(x, y, px[k], py[l]), ans);
            }

            cout << ans;
            if(!Q) cout << endl;
            else cout << ' ';
        }
    }
}
