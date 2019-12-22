#include <bits/stdc++.h>
using namespace std;

int Q = 10000;

int main() {
    int n, xlb , xub, ylb, yub;
    cin >> n;
    srand(time(NULL));
    default_random_engine gen;
    uniform_int_distribution<int> xdist(0,10000), ydist(1000000, 1010000);
    for(int I = 0; I < n; ++I) {
        int x = xdist(gen), y = ydist(gen);
        x -= x%10;
        y -= y%10;
        cout << x << ' ' << y << ' ' << Q << endl;
        for(int i = 0; i < Q; ++i) {
            int cx = xdist(gen), cy = ydist(gen);
            cx -= cx%10;
            cy -= cy%10;
            cout << cx << ' ' << cy;
            if(i + 1 == Q) cout << endl;
            else cout << ' ';
        }
    }
}
