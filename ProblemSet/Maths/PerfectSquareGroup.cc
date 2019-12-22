/**
 * Judge: http://codeforces.com/contest/980/problem/D
 * Contest: CodeForces Round480 Div2
 * Status: AC
 * Description: Given and array, count for each subarray how many different groups you need such that all products within a group are a perfect square
 * Solution: a*b is a perfect square is a equivalence relation
 **/
#include<bits/stdc++.h>
using namespace std;

int l[5050];
long long v[5050];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(l, -1, sizeof(l));

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        for(long long j = 2; j*j <= abs(v[i]); ++j) {
            while(abs(v[i])%(j*j) == 0) v[i] /= (j*j);
        }
    }

    for(int i = 0; i < n; ++i) {
        long long cur = v[i];
        if(l[i] != -1) continue;
        if(cur == 0) continue;
        int curp = i;
        for(int j = i + 1; j < n; ++j) {
            if(v[i] == v[j]) {
                l[j] = curp;
                curp = j;
            }
        }
    }
    int ans[n+1] = {};
    for(int i = 0; i < n; ++i) {
        int curans = 0;
        for(int j = i; j < n; ++j) {
            if(v[j] != 0 && l[j] < i) curans++;
            ans[max(curans,1)]++;
        }
    }
    for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}
