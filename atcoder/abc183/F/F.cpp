#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
int n, q, c[mxN], par[mxN];
map<int, int> mp[mxN];

int find(int x) {
    return (x==par[x]?x:par[x]=find(par[x]));
}
void merge(int a, int b) {
    a=find(a), b=find(b);
    if (a^b) {
        if (mp[a].size()>mp[b].size())
            swap(a, b);
        par[a]=b;
        for (auto p:mp[a])
            mp[b][p.first]+=p.second;
        mp[a].clear();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1; i<=n; ++i)
        cin >> c[i], par[i]=i, mp[i][c[i]]=1;
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t&1)
            merge(a, b);
        else
            cout << (mp[find(a)].count(b)?mp[find(a)][b]:0) << '\n';
    }
}

