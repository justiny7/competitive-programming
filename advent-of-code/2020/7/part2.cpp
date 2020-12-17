#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;

const int mxN=1e3+1;
int n, ans, st, dp[mxN];
map<string, int> mp;
vector<pii> adj[mxN];

int dfs(int v, int p=0) {
    if (~dp[v])
        return dp[v];
    int cur=0;
    for (pii u:adj[v])
        if (u.first^p)
            cur+=u.second*(1+dfs(u.first, v));
    return dp[v]=cur;
}

int main() {
    memset(dp, -1, sizeof(dp));
    freopen("test.txt", "r", stdin);
    string s;
    while (1) {
        getline(cin, s);
        if (s.empty())
            break;
        stringstream ss(s);
        string name, ret;
        for (int i=0; i<2; ++i)
            ss >> ret, name+=ret;
        ss >> ret >> ret;
        if (!mp.count(name))
            mp[name]=n++;
        while (1) {
            string xs; ss >> xs;
            if (xs=="no")
                break;
            int x=0;
            for (char c:xs)
                x=x*10+(c-'0');
            string cur;
            for (int i=0; i<2; ++i)
                ss >> ret, cur+=ret;
            ss >> ret;
            if (!mp.count(cur))
                mp[cur]=n++;
            adj[mp[name]].emplace_back(mp[cur], x);
            char c=ret.back();
            if (c=='.')
                break;
        }
    }
    for (auto p:mp)
        if (p.first=="shinygold")
            st=p.second;
    cout << dfs(st) << '\n';
}

