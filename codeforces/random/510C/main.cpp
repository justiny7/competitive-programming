#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=101;
int n, vis[26];
string s[mxN];
vector<int> adj[26], topo;

bool dfs(int v) {
    vis[v]=1;
    for (int u:adj[v])
        if (vis[u]==1 || (!vis[u] && !dfs(u)))
            return 0;
    vis[v]=2;
    topo.pb(v);
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    if (n==1)
        return cout << "abcdefghijklmnopqrstuvwxyz\n", 0;
    for (int i=0; i<n; ++i)
        cin >> s[i];
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j) {
            bool f=0;
            for (int k=0; k<(int)min(s[i].size(), s[j].size()); ++k)
                if (s[i][k]^s[j][k]) {
                    adj[s[i][k]-'a'].pb(s[j][k]-'a');
                    f=1;
                    break;
                }
            if (!f && s[i].size()>s[j].size())
                return cout << "Impossible\n", 0;
        }
    for (int i=0; i<26; ++i)
        if (!vis[i] && !dfs(i))
            return cout << "Impossible\n", 0;
    for (int i=25; ~i; --i)
        cout << char(topo[i]+'a');
    cout << '\n';
}

