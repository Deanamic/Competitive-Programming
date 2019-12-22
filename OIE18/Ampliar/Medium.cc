#include <bits/stdc++.h>
using namespace std;


vector<string> ch(26);

string transform(const string& s) {
    string nw = "";
    for(char c : s) {
        nw += ch[c-'a'];
    }
    return nw;
}
int main() {
    string s;
    int k, i;
    while(cin >> s >> k >> i) {
        for(int j = 0; j < 26; ++j) {
            cin >> ch[j];
        }

        while(k--) {
            s = transform(s);
        }
        cout << s[i-1] << endl;
    }
}
