#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

const int mxN=100;
int n, ans=-1;
vector<pii> adj[mxN];
map<string, int> mp;
bool vis[mxN];

void go(int v, int cnt=1, int cost=0) {
    if (cnt==n) {
        ans=max(ans, cost);
        return;
    }
    vis[v]=1;
    for (pii u:adj[v])
        if (!vis[u.fi]) {
            go(u.fi, cnt+1, cost+u.se);
        }
    vis[v]=0;
}

int main() {
    freopen("test.txt", "r", stdin);
    {
        string s;
        while (1) {
            getline(cin, s);
            if (s.empty())
                break;
            stringstream ss(s);
            string s1, s2, garbage;
            int w;
            ss >> s1;
            if (!mp.count(s1))
                mp[s1]=n++;
            ss >> garbage >> s2;
            if (!mp.count(s2))
                mp[s2]=n++;
            ss >> garbage >> w;
            adj[mp[s1]].emplace_back(mp[s2], w);
            adj[mp[s2]].emplace_back(mp[s1], w);
        }
    }
    for (int i=0; i<n; ++i)
        go(i);
    cout << ans << '\n';
}

