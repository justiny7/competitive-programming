/*
ID: justiny7
LANG: C++
TASK: schlnet
*/

//Idea - use strongly connected components
//Answer to Subtask A is # of SCC's w/ indegree 0, answer to Sutask B is max of source & sinks
//Got it second try b/c I forgot about the 1-component corner case
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

ifstream fin("schlnet.in");
ofstream fout("schlnet.out");

const int mxN=101;
int n, comp[mxN], cmpcnt=1, in[mxN], out[mxN];
vector<int> adj[mxN], radj[mxN], ord;
bool vis[mxN];

void topo(int v) {
    vis[v]=1;
    for (int u:adj[v])
        if (!vis[u])
            topo(u);
    ord.pb(v);
}

void get_cmp(int v) {
    comp[v]=cmpcnt;
    for (int u:radj[v])
        if (!comp[u])
            get_cmp(u);
}

int main(void) {
    fin >> n;
    for (int i=1; i<=n; ++i) {
        int k; fin >> k;
        while (k)
            adj[i].pb(k), radj[k].pb(i), fin >> k;
    }
    for (int i=1; i<=n; ++i)
        if (!vis[i])
            topo(i);
    for (int i=n-1; i>=0; --i) {
        int v=ord[i];
        if (!comp[v])
            get_cmp(v), ++cmpcnt;
    }
    for (int i=1; i<=n; ++i)
        for (int u:adj[i])
            if (comp[i]!=comp[u])
                ++in[comp[u]], ++out[comp[i]];
    int ans1=0, ans2=0;
    for (int i=1; i<cmpcnt; ++i) {
        if (!in[i])
            ++ans1;
        if (!out[i])
            ++ans2;
    }
    if (cmpcnt>2)
        fout << ans1 << '\n' << max(ans1, ans2) << '\n';
    else
        fout << "1\n0\n";
}
