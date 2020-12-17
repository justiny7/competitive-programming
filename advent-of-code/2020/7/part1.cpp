#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+1;
int n, ans, targ, f;
map<string, int> mp;
vector<int> adj[mxN];

void dfs(int v, int p=0) {
    for (int u:adj[v])
        if (u^p)
            dfs(u, v);
    if (v==targ)
        f=1;
}

int main() {
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
            string x; ss >> x;
            if (x=="no")
                break;
            string cur;
            for (int i=0; i<2; ++i)
                ss >> ret, cur+=ret;
            ss >> ret;
            if (!mp.count(cur))
                mp[cur]=n++;
            adj[mp[name]].push_back(mp[cur]);
            char c=ret.back();
            if (c=='.')
                break;
        }
    }
    for (auto p:mp)
        if (p.first=="shinygold")
            targ=p.second;
    for (int i=0; i<n; ++i) {
        f=0, dfs(i);
        if (f)
            ++ans;
    }
    cout << ans-1 << '\n';
}

