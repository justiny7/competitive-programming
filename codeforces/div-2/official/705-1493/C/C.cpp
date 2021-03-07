#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1, mxC=26;
int n, k, pref[mxN][mxC];
string s;

void solve() {
    cin >> n >> k >> s;
    memset(pref, 0, sizeof(pref[0])*(n+1));
    for (int i=1; i<=n; ++i) {
        pref[i][s[i-1]-'a']=1;
        for (int j=0; j<mxC; ++j)
            pref[i][j]+=pref[i-1][j];
    }
    for (int i=n; ~i; --i) {
        int need[mxC]={}, left=n-i, tot=0;
        for (int j=0; j<mxC; ++j)
            need[j]=(k-pref[i][j]%k)%k, tot+=need[j];
        if (tot>left || (left-tot)%k)
            continue;
        return;
    }
    cout << "-1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

