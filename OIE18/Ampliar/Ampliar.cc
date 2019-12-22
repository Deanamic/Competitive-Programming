#include <bits/stdc++.h>
using namespace std;

vector<string> ch(26);
vector<vector<long long>> l(26, vector<long long>(10010,1));

void get(char c, long long pos, int kk) {
    while(pos <= 0);
    if(kk == 0) {
        cout << c << endl;
        return;
    }

    string cur = ch[c-'a'];

    long long sum = 0;
    int pp = 0;
    for(; sum < pos; ++pp) {
        sum += l[cur[pp]-'a'][kk-1];
    }
    --pp;
    get(cur[pp], pos - sum + l[cur[pp]-'a'][kk-1], kk-1);
}

int main() {
    string s;
    int k, i;
    while(cin >> s >> k >> i) {

        s.push_back('a');
        for(int j = 0; j < 26; ++j) {
            cin >> ch[j];
            l[j][1] = ch[j].size();
        }
        if(k == 0) {
            cout << s[i-1] << endl;
            continue;
        }

        for(int j = 2; j <= k; ++j) {
            for(int h = 0; h < 26; ++h) {
                l[h][k] = 0;
                for(char c : ch[h]) l[h][j] += l[c-'a'][j-1];
            }
        }
        int pos = 0;
        long long sum = 0;

        for(; sum < i; ++pos) {
            sum += l[s[pos]-'a'][k];
        }
        --pos;
        get(s[pos], i - sum + l[s[pos]-'a'][k], k);
    }
}
