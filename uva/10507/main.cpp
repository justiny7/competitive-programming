#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=30;
int n, m;
vector<int> adj[mxN];
char c[3];
bool vis[mxN];

int main(void) {
    while (scanf("%d %d", &n, &m)!=EOF) {
        memset(vis, 0, sizeof(vis));
        for (int i=0; i<mxN; ++i)
            adj[i].clear();
        scanf("%s", c);
        for (int i=0; i<m; ++i) {
            char t[2];
            scanf("%s", t);
            adj[t[0]-'A'].pb(t[1]-'A');
            adj[t[1]-'A'].pb(t[0]-'A');
        }
        for (int i=0; i<3; ++i)
            vis[c[i]-'A']=1;
        int curlvl=0;
        set<int> nxt;
        do {
            nxt.clear();
            for (int i=0; i<mxN; ++i) {
                if (vis[i])
                    continue;
                int cnt=0;
                for (int u:adj[i])
                    if (vis[u])
                        ++cnt;
                if (cnt>=3)
                    nxt.insert(i);
            }
            for (int i:nxt)
                vis[i]=1;
            ++curlvl;
        } while (nxt.size());
        int ans=0, cnt=0;
        for (int i=0; i<mxN; ++i)
            if (vis[i])
                ++cnt;
        if (cnt==n)
            printf("WAKE UP IN, %d, YEARS\n", curlvl-1);
        else
            printf("THIS BRAIN NEVER WAKES UP\n");
    }
}
