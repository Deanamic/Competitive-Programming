#include <bits/stdc++.h>
using namespace std;

using LL = long long;

#define FOR(i,a,b) for(int i = (a), i < (int)(b); ++i)
using T = double; 
struct cmplx {
  T x,y;
  cmplx operator *(const cmplx& c) const { return cmplx{x*c.x-y*c.y, x*c.y+y*c.x}; }
  cmplx operator +(const cmplx& c) const { return cmplx{x+c.x, y+c.y};}
  void operator +=(const cmplx& c) const { x+=c.x, y+=c.y;}
};

int main() {
  
}
