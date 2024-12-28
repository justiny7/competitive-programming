#include <bits/stdc++.h>
#define pb push_back
using namespace std;

ofstream fout("output.txt");

const int mxN=51;
int n;
string in, out;
bool ans[mxN][mxN];
vector<int> adj[mxN];

void dfs(int v, int i) {
    ans[i][v]=1;
    for (int u:adj[v])
        if (!ans[i][u])
            dfs(u, i);
}

int main() {
    int t; cin >> t;
    for (int tt=1; tt<=t; ++tt) {
        memset(ans, 0, sizeof(ans));
        for (int i=0; i<mxN; ++i)
            adj[i].clear();
        cin >> n >> in >> out;
        for (int i=0; i<n; ++i) {
            if (out[i]=='N')
                continue;
            for (int j=0; j<n; j++)
                if (in[j]=='Y' && abs(i-j)==1)
                    adj[i].pb(j);
        }
        //for (int i=0; i<n; ++i) {
            //cout << i << ":\n";
            //for (int u:adj[i])
                //cout << u << " ";
            //cout << '\n';
        //}
        for (int i=0; i<n; ++i)
            dfs(i, i);
        fout << "Case #" << tt << ":\n";
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j)
                fout << (ans[i][j]?"Y":"N");
            fout << '\n';
        }
    }
}
