#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll oo = 0x3f3f3f3f3f3f3f3fLL;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define has(c, e) ((c).find(e) != (c).end())
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()

struct p{
    ld x;
    ld y;
    ld z;
};

ld dist(p a, p b) {
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}

p cross(p a, p b) {
    return {a.y * b.z - a.z * b.y, -a.x * b.z + a.z * b.x, a.x * b.y - a.y * b.x};
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<p> v(n);
    for (int i=0; i<n; ++i)
        cin>>v[i].x>>v[i].y>>v[i].z;
    p q={0, 0, 0};
    ld dis=0;
    int index;
    for (int i=0; i<n; ++i) {
        if (dist(q, v[i])>dis) {
            dis=dist(q, v[i]);
            index=i;
        }
    }
    p a=v[index], aux;
    int ia=index;
    p vec={a.x-q.x, a.y-q.y, q.z-q.z};
    ld l=0;
    ld u=10;
    ld m, d;
    for (int i=0; i<100; ++i) {
        m=(l+u)/2;
        aux={q.x+m*vec.x, q.y+m*vec.y, q.z+m*vec.z};
        bool ok=1;
        d=dist(a, aux);
        for (int j=0; ok and j<n; ++j) {
            if (j!=ia and dist(v[j], aux)>d+1e-6) {
                ok=0;
                index=j;
            }
        }
        if (ok)
            l=m;
        else
            u=m;
    }
    d=sqrt(d);
    p b=v[index];
    int ib=index;
    q=aux;
    vec={(a.x-q.x+b.x-q.x)/2, (a.y-q.y+b.y-q.y)/2, (a.z-q.z+b.z-q.z)/2};
    l=0;
    u=10;
    
    cout<<q.x<<" "<<q.y<<" "<<q.z<<endl;
    for (int i=0; i<100; ++i) {
        m=(l+u)/2;
        aux={q.x+m*vec.x, q.y+m*vec.y, q.z+m*vec.z};
        bool ok=1;
        d=dist(a, aux);
        for (int j=0; ok and j<n; ++j) {
            if (j!=ia and j!=ib and dist(v[j], aux)>d+1e-6) {
                ok=0;
                index=j;
            }
        }
        if (ok)
            l=m;
        else
            u=m;
    }
    d=sqrt(d);
    ld ddd=d;
    int ic=index;
    p c=v[index];
    q=aux;
    vec=cross({b.x-a.x, b.y-a.y, b.z-a.z}, {c.x-a.x, c.y-a.y, c.z-a.z});
    cout<<"VEC:"<<vec.x<<" "<<vec.y<<" "<<vec.z<<endl;
    cout<<"INDEXOS:"<<ia<<" "<<ib<<" "<<ic<<endl;
    cout<<"a:"<<a.x<<" "<<a.y<<" "<<a.z<<endl;
    
    
    l=0;
    u=1;
    
    cout<<aux.x<<" "<<aux.y<<" "<<aux.z<<endl;
    
    for (int i=0; i<100; ++i) {
        m=(l+u)/2;
        aux={q.x+m*vec.x, q.y+m*vec.y, q.z+m*vec.z};
        bool ok=1;
        d=dist(a, aux);
        for (int j=0; ok and j<n; ++j) {
            if (j!=ia and j!=ib and j!=ic and (dist(v[j], aux)>d+1e-6)) {
                ok=0;
                index=j;
            }
        }
        if (ok)
            l=m;
        else
            u=m;
    }
    cout<<aux.x<<" "<<aux.y<<" "<<aux.z<<endl;
    d=sqrt(d);
    
    cout<<d<<endl<<sqrt(dist({0, 0, 0}, aux))<<endl;
    
	return 0;
}
