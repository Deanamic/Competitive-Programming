/**
 * Judge: http://codeforces.com/gym/101635
 * Contest: SWERC 2014 Problem C
 * Status: AC
 * Description: Given 1x2 pieces of dominoes, find ways to fill up a 8xN board.
 * Solution: Describe State transitions as products with a matrix coding states as bitmasks.
*/

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000

int n;
long long m;

struct Matrix{
    int n;
    vector<vector<long long>> M;
    Matrix(int N) {
        n = N;
        M = vector<vector<long long>> (n, vector<long long> (n,0));
    }

    Matrix operator *(const Matrix& m1) {
        Matrix ans = Matrix(n);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < n; ++k) {
                    ans.M[i][j] += M[i][k] * m1.M[k][j];
                    ans.M[i][j] %= MOD;
                }
            }
        }
        return ans;
    }

    Matrix exp(long long p) {
        Matrix ans(n);
        Matrix cur = *this;
        for(int i = 0; i < n; ++i) ans.M[i][i] = 1;
        while(p) {
            if(p&1) ans = ans * cur;
            cur = cur*cur;
            p >>= 1;
        }
        return ans;
    }

};

int fib[10];

//We calculate the number of ways we can go from mask a to b.
//We put 1x2 blocks to satify this and then fill the spaces
long long getval(int a, int b) {
    if(a & b) {
        return 0;
    }
    int c = a|b;
    int sp = 0;
    long long ways = 1;
    for(int i = 0; i < n; ++i) {
        if(!(c & (1<<i))) sp++;
        else {
            ways *= fib[sp];
            sp = 0;
            ways %= MOD;
        }
    }
    ways *= fib[sp];
    ways %= MOD;
    return ways;
}
int main() {

    cin >> n >> m;
    fib[0] = fib[1] = 1;
    for(int i = 2; i < 10; ++i) fib[i] = fib[i-1] + fib[i-2];
    Matrix mat(1<<n);
    for(int i = 0; i < (1<<n); ++i) {
        for(int j = 0; j < (1<<n); ++j) {
            mat.M[i][j] = getval(i, j);
        }
    }
    cout << mat.exp(m).M[0][0] << endl;
}
