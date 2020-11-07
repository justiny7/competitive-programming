#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;

ifstream fin("meeting.in");
ofstream fout("meeting.out");

int n, m;
vector<pii> adj1[17], adj2[17];
set<int> t1, t2;
bool vis1[17], vis2[17];

void dfs1(int v=1, int t=0) {
    vis1[v]=1;
    if (v==n) {
        t1.insert(t);
        vis1[v]=0;
        return;
    }
    for (pii u:adj1[v])
        if (!vis1[u.fi])
            dfs1(u.fi, t+u.se);
    vis1[v]=0;
}

void dfs2(int v=1, int t=0) {
    vis2[v]=1;
    if (v==n) {
        t2.insert(t);
        vis2[v]=0;
        return;
    }
    for (pii u:adj2[v])
        if (!vis2[u.fi])
            dfs2(u.fi, t+u.se);
    vis2[v]=0;
}

int main(void) {
    fin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        adj1[a].push_back({b, c});
        adj2[a].push_back({b, d});
    }
    dfs1(); dfs2();
    auto it1=t1.begin(), it2=t2.begin();
    while (it1!=t1.end() && it2!=t2.end() && *it1!=*it2) {
        if (*it1<*it2)
            ++it1;
        else
            ++it2;
    }
    if (it1==t1.end() || it2==t2.end())
        fout << "IMPOSSIBLE\n";
    else
        fout << *it1 << '\n';
}
