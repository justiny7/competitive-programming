//USACO Silver February 2020 Problem 1
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;
//Yay worked 3rd try! (the first two times I didn't read mxN was 1e5, I thought it was 1e4 xd)
ifstream fin("swap.in");
ofstream fout("swap.out");

int n, k, m, a[100001], c[100001], grp[100001], o[100001], tag=1;
vector<int> ord[100001];
pii sw[101];

void dfs(int u, int cur=0) {
    grp[u]=tag;
    ord[tag].push_back(u);
    o[u]=cur;
    if (!grp[a[u]-1])
        dfs(a[u]-1, cur+1);
}

int main(void) { //finding permutations of cycles 
    fin >> n >> m >> k;
    for (int i=0; i<m; ++i)
        fin >> sw[i].fi >> sw[i].se, --sw[i].fi;
    for (int i=0; i<n; ++i)
        a[i]=i+1;
    for (int i=0; i<m; ++i)
        reverse(a+sw[i].fi, a+sw[i].se);
    for (int i=0; i<n; ++i)
        if (!grp[i])
            dfs(i), ++tag;
    for (int i=0; i<n; ++i)
        fout << 1+ord[grp[i]][(o[i]+(k%ord[grp[i]].size()))%ord[grp[i]].size()] << '\n';
}
