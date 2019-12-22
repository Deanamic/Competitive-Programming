#include<bits/stdc++.h>
using namespace std;

vector<int> fact(int n) {
	vector<int> ans;
	for(int i = 2; i <= n; ++i) {
		if(n % i == 0) {
			while(n % i == 0) {
				n /= i;
			}
			ans.push_back(i);
		}
	}
	return ans;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

}
