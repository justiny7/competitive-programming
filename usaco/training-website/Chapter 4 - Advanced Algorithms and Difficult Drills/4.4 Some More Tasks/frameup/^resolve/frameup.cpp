/*
ID: justiny7
LANG: C++11
TASK: frameup
*/

#include <bits/stdc++.h>
using namespace std;

const int mxN=31, mxV=26;
int n, m, cnt, in[mxN];
string s[mxN];
array<int, 4> bounds[mxN];
vector<int> adj[mxN];
bool vis[mxN];
vector<string> ans;
string cur;

void dfs(int v, int k=1) {
    if (k==cnt) {
        ans.push_back(cur);
        return;
    }
    for (int u:adj[v])
        --in[u];
    for (int u=0; u<mxV; ++u) {
        if (in[u] || vis[u] || bounds[u][0]==INT_MAX)
            continue;
        vis[u]=1;
        cur+=char('A'+u);
        dfs(u, k+1);
        cur.pop_back();
        vis[u]=0;
    }
    for (int u:adj[v])
        ++in[u];
}

int main() {
    ifstream cin("frameup.in");
    ofstream cout("frameup.out");
    cin >> n >> m;
    for (int i=0; i<mxV; ++i)
        bounds[i]={INT_MAX, INT_MIN, INT_MAX, INT_MIN};
    for (int i=0; i<n; ++i) {
        cin >> s[i];
        for (int j=0; j<m; ++j) {
            if (s[i][j]=='.')
                continue;
            int c=(s[i][j]-'A');
            bounds[c][0]=min(bounds[c][0], i);
            bounds[c][1]=max(bounds[c][1], i);
            bounds[c][2]=min(bounds[c][2], j);
            bounds[c][3]=max(bounds[c][3], j);
        }
    }
    for (int i=0, c; i<mxV; ++i) {
        if (bounds[i][0]==INT_MAX)
            continue;
        ++cnt;
        for (int j=bounds[i][0]; j<=bounds[i][1]; ++j) {
            if (s[j][bounds[i][2]]^'.') {
                c=(s[j][bounds[i][2]]-'A');
                if (c^i && find(adj[i].begin(), adj[i].end(), c)==adj[i].end())
                    adj[i].push_back(c), ++in[c];
            }
            if (s[j][bounds[i][3]]^'.') {
                c=(s[j][bounds[i][3]]-'A');
                if (c^i && find(adj[i].begin(), adj[i].end(), c)==adj[i].end())
                    adj[i].push_back(c), ++in[c];
            }
        }
        for (int j=bounds[i][2]; j<=bounds[i][3]; ++j) {
            if (s[bounds[i][0]][j]^'.') {
                c=(s[bounds[i][0]][j]-'A');
                if (c^i && find(adj[i].begin(), adj[i].end(), c)==adj[i].end())
                    adj[i].push_back(c), ++in[c];
            }
            if (s[bounds[i][1]][j]^'.') {
                c=(s[bounds[i][1]][j]-'A');
                if (c^i && find(adj[i].begin(), adj[i].end(), c)==adj[i].end())
                    adj[i].push_back(c), ++in[c];
            }
        }
    }
    for (int i=0; i<mxV; ++i)
        if (bounds[i][0]^INT_MAX && !in[i]) {
            vis[i]=1;
            cur+=char('A'+i);
            dfs(i);
            cur.pop_back();
            vis[i]=0;
        }
    for (string s:ans)
        cout << s << '\n';
}

