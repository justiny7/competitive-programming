#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("test.txt", "r", stdin);
    int t, cur=0; cin >> t;
    string s; cin >> s;
    vector<int> v;
    for (int i=0; i<s.size(); ++i) {
        if (s[i]>='0' && s[i]<='9')
            cur=cur*10+(s[i]-'0');
        else if (s[i]==',' && cur)
            v.push_back(cur), cur=0;
    }
    if (cur)
        v.push_back(cur);
    for (int i=t;; ++i) {
        int f=-1;
        for (int j:v)
            if (i%j==0)
                f=j;
        if (~f) {
            cout << (i-t)*f << '\n';
            break;
        }
    }
}

