
#include <bits/stdc++.h>
using namespace std;

int main() {
  double l1,l2,p1,p2;
  cout.precision(3);
  cout.setf(ios::fixed);
  while(cin >> l1 >> l2 >> p1 >> p2) {
    double p3 = 1.0 - p1 - p2;
    cout << (5.0*p1 + 10.0*p2 + 15.0*p3)/(1.0-p1-(1-l1)*p2-(1-l2)*p3) << endl;
  }
}

