#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("test.txt", "r", stdin);
    int ans=0;
    string s="";
    while (cin >> s) {
        int n=s.size(), f=0, f2=0;
        map<string, vector<int>> mp;
        for (int i=0; i<n-1; ++i) {
            mp[s.substr(i, 2)].push_back(i);
            if (i<n-2 && s[i]==s[i+2])
                f2=1;
        }
        for (auto p:mp) {
            vector<int> v=p.second;
            f|=(v.size()>1 && v.back()-v[0]>1);
        }
        if (f && f2)
            ++ans;
    }
    cout << ans << '\n';
}

