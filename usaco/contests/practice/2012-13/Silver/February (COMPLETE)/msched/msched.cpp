/*
 * Accidentally stumbled upon a memoized dfs answer XD
 * Idea - for each cow, the time after milking that cow is the maximum
 * of all the cows that needs to be milked before it + the time it takes
 * to milk that cow. We memoize the times of all the cows to speed up
 * the dfs
 *
*/

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

ifstream fin("msched.in");
ofstream fout("msched.out");

const int mxN=1e4+1;
int n, m, t[mxN], finish[mxN], ans;
vector<int> adj[mxN];

int dfs(int v) {
    if (finish[v])
        return finish[v];
    int tot=t[v], cmax=0;
    for (int u:adj[v])
        cmax=max(cmax, dfs(u));
    return finish[v]=tot+cmax;
}

int main(void) {
    fin >> n >> m;
    for (int i=1; i<=n; ++i)
        fin >> t[i];
    while (m--) {
        int a, b;
        fin >> a >> b;
        adj[b].pb(a);
    }
    for (int i=1; i<=n; ++i)
        ans=max(ans, dfs(i));
    fout << ans << '\n';
}
