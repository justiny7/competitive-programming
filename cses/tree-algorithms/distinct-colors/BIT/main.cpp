//Flattened tree, then copied code from Distinct Values Queries
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=2e5+1;
int n, t, c[mxN], in[mxN], out[mxN], bit[mxN*2], ans[mxN];
array<int, 3> q_a[mxN];
vector<int> adj[mxN], tree;
map<int, int> seen;

void dfs(int v=1, int p=-1) {
    in[v]=t++;
    tree.pb(v);
    for (int u:adj[v])
        if (u!=p)
            dfs(u, v);
    out[v]=t++;
    tree.pb(v);
}

void upd(int i, int x) {
    for (++i; i<=t; i+=i&(-i))
        bit[i]+=x;
}

int query(int i) {
    int sum=0;
    for (++i; i>0; i-=i&(-i))
        sum+=bit[i];
    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> c[i];
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    for (int i=1; i<=n; ++i)
        q_a[i-1][0]=out[i], q_a[i-1][1]=in[i], q_a[i-1][2]=i-1;
    sort(q_a, q_a+n);
    for (int i=0, j=0; i<t || j<n; ++j) {
        while (i<t && i<=q_a[j][0]) {
            int v=tree[i];
            if (seen.count(c[v]))
                upd(seen[c[v]], -1);
            upd(i, 1);
            seen[c[v]]=i++;
        }
        ans[q_a[j][2]]=query(q_a[j][0])-query(q_a[j][1]-1);
    }
    for (int i=0; i<n; ++i)
        cout << ans[i] << " ";
    cout << '\n';
}
