#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e3+1;
int n;
map<string, int> mp;

void add(string s, int a) {
    if (!mp.count(s))
        mp[s]=a;
    else
        mp[s]=min(mp[s], a);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a; string s;
        cin >> a >> s;
        sort(s.begin(), s.end());
        add(s, a);
        for (int i=0; i<s.size(); ++i)
            add(s.substr(i, 1), a);
        for (int i=0; i<s.size(); ++i)
            for (int j=i+1; j<s.size(); ++j) {
                string ss=s.substr(i, 1)+s.substr(j, 1);
                add(ss, a);
            }
    }
    string s="ABC";
    int ans=INT_MAX;
    for (int i=0; i<3; ++i) //wtf is this ugly-ass code smh
        for (int j=0; j<3; ++j) {
            if (j==i)
                continue;
            for (int k=0; k<3; ++k) {
                if (k==j || k==i)
                    continue;
                string x=s.substr(i, 1), y=s.substr(j, 1), z=s.substr(k, 1);
                if (mp.count(x) && mp.count(y) && mp.count(z))
                    ans=min(ans, mp[x]+mp[y]+mp[z]);
            }
        }
    for (int i=0; i<3; ++i) {
        string a=s.substr(i, 1), b=(i==0?"BC":(i==1?"AC":"AB"));
        if (mp.count(a) && mp.count(b))
            ans=min(ans, mp[a]+mp[b]);
    }
    string p="ABC";
    if (mp.count(p))
        ans=min(ans, mp[p]);
    cout << (ans==INT_MAX?-1:ans) << '\n';
}

