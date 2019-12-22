#include <bits/stdc++.h>

using namespace std;

struct qu{
    int l, r, ind;
};

const long long MOD = 1e9+7;
int n, m;
vector <int>v;
vector <long long>ans;

vector <long long>mult(vector <long long>& vv, int k) {
    vector <long long>res(m, 0);
    for (int i = 0; i < m; ++i) {
        res[i] = (res[i] + vv[i])%MOD;
        res[(i+k)%m] = (res[(i+k)%m] + vv[i])%MOD;
    }
    return res;
}

int mult2(vector <long long>& vv, vector <long long>& vv2) {
    long long res = (vv[0]*vv2[0])%MOD;
    for (int i = 1; i < m; ++i) {
        res += vv[i]*vv2[m-i];
        res %= MOD;
    }
    return res%MOD;
}

void div(int l, int r, vector <qu>& q) {
    if (l == r) {
        for (int i = 0; i < q.size(); ++i) {
            if (v[l] == 0) ans[q[i].ind] = 2;
            else ans[q[i].ind] = 1;
        }
        return;
    }
    int mid = (l+r)>>1;
    vector <vector <long long> >esq(mid-l+1, vector <long long>(m, 0));
    esq[0][0] = 1;
    esq[0][v[mid]]++;
    for (int i = 1; i <= mid-l; ++i) {
        esq[i] = mult(esq[i-1], v[mid-i]);
    }
    vector <vector <long long> >dre(r-mid, vector <long long>(m, 0));
    dre[0][0] = 1;
    dre[0][v[mid+1]]++;
    for (int i = 1; i < r-mid; ++i) {
        dre[i] = mult(dre[i-1], v[mid+i+1]);
    }
    vector <qu>a, b;
    for (int i = 0; i < q.size(); ++i) {
        if (q[i].r <= mid) a.push_back(q[i]);
        else if (q[i].l > mid) b.push_back(q[i]);
        else ans[q[i].ind] = mult2(esq[mid-q[i].l], dre[q[i].r-mid-1]);
    }
    div(l, mid, a);
    div(mid+1, r, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    v = vector <int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        v[i] %= m;
    }
    int qq;
    cin >> qq;
    vector <qu>q(qq);
    for (int i = 0; i < qq; ++i) {
        cin >> q[i].l >> q[i].r;
        --q[i].l; --q[i].r;
        q[i].ind = i;
    }
    ans = vector <long long>(qq);
    div(0, n-1, q);
    for (int i = 0; i < qq; ++i) cout << ans[i] << '\n';
}
