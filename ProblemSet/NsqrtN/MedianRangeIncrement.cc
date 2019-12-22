/**
 * Judge: http://codeforces.com/gym/101470
 * Contest: SEERC 2014 Problem E
 * Status: AC
 * Description: Given N numbers find the median with range increments
 * Solution: Use \sqrt(N) size buckets and mantain the values
*/

#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[65526];
int sum[3000];
int sq;
int n, q;
int M;
const int oo = 1500000000;

void updateB(int b, int left, int right) {
    stack<pair<int,int>> s;
    for(int i = b; i < b+sq; ++i) {
        if(a[i].second < right && a[i].second >= left) s.push({a[i].first, i});
    }
    for(int i = b+sq-1; s.size() && i >= b; --i) {
        if(a[i].first == s.top().first) {
            swap(a[i], a[s.top().second]);
            a[i].first++;
            s.pop();
        }
    }
    assert(s.empty());
}

bool isMean(int m) {
    int cnt = 0;
    for(int i = 0; i < n; i += sq) {
        int l = i-1, r = i+sq;
        while(l + 1 < r) {
            int mid = (l+r)>>1;
            if(a[mid].first + sum[i/sq] > m) r = mid;
            else l = mid;
        }
        cnt += (r - i);
    }
    return cnt >= (n+1)/2;
}

int main() {
    #ifndef LOCAL
    //freopen("F.in", "r", stdin);
    #endif
    while(cin >> n >> q, n && q) {
        memset(sum, 0, sizeof(sum));
        for(sq = 1; sq*sq < n; ++sq);
        int b[n];
        for(int i = 0; i < n; ++i) {
            cin >> a[i].first;
            b[i] = a[i].first;
            a[i].second = i;
        }
        int it = n;
        while(it < sq*sq) a[it++] = {oo, oo};
        sort(b, b+n);
        M = b[n/2];
        for(int i = 0; i*sq < n; ++i) {
            sort(a + i*sq, a + (i+1)*sq);
        }
        while(q--) {
            int l,r;
            cin >> l >> r;
            --l;
            int lb = l/sq;
            int rb = r/sq;
            for(int i = lb+1; i < rb; ++i) sum[i]++;
            updateB(lb*sq, l, r);
            if(lb != rb) updateB(rb*sq, l, r);
            if(isMean(M)) cout << M << endl;
            else cout << ++M << endl;

        }
    }
}
