//Yay worked first try
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

ifstream fin("closing.in");
ofstream fout("closing.out");

const int mxN=2e5+1;
int n, m, par[mxN], sz[mxN], seq[mxN], cur;
vector<int> adj[mxN];
bool ans[mxN], in[mxN];

void make(int v) {
    par[v]=v, sz[v]=1, ++cur;
}

int find(int v) {
    if (v==par[v])
        return v;
    return par[v]=find(par[v]);
}

bool combine(int a, int b) {
    a=find(a); b=find(b);
    if (a!=b) {
        if (sz[a]<sz[b])
            swap(a, b);
        --cur, par[b]=a, sz[a]+=sz[b];
        return 1;
    }
    return 0;
}

int main() {
    fin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a, b;
        fin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i=0; i<n; ++i)
        fin >> seq[i], make(i+1);
    for (int i=n-1; i>=0; --i) {
        int v=seq[i];
        in[v]=1;
        for (int u:adj[v])
            if (in[u])
                combine(v, u);
        ans[i]=(cur==i+1);
    }
    for (int i=0; i<n; ++i)
        fout << (ans[i]?"YES\n":"NO\n");
}
