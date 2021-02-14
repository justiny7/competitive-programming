#include <bits/stdc++.h>
using namespace std;

const int mxN=5e4+1, mxK=11;
int n, k, ans, dp[mxN], pref[mxK][mxN];
string cows[mxK];
stack<pair<int, int>> st[mxK];
map<vector<int>, int> mp;

int main() {
    ifstream cin("cbs.in");
    ofstream cout("cbs.out");
    cin >> k >> n;
    for (int i=0; i<k; ++i)
        cin >> cows[i];
    mp[vector<int>(k, 0)]=0;
    for (int i=1; i<=n; ++i) {
        int mx=0;
        vector<int> here;
        for (int j=0; j<k; ++j) {
            pref[j][i]=pref[j][i-1]+(cows[j][i-1]=='('?1:-1);
            here.push_back(pref[j][i]);
            while (st[j].size() && pref[j][i]<=st[j].top().first)
                st[j].pop();
            if (st[j].size())
                mx=max(mx, st[j].top().second);
            st[j].emplace(pref[j][i], i);
        }
        if (mp.count(here) && mp[here]>=mx)
            dp[i]=1+dp[mp[here]];
        ans+=dp[i];
        mp[here]=i;
    }
    cout << ans << '\n';
}

