#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using db=double;

const int mxN=3e5+1;
int n, q, t, in[mxN], out[mxN];
db bit[mxN*2], a[mxN*2];
vector<int> adj[mxN];

void dfs(int v=1, int p=0) {
    in[v]=t++;
    for (int u:adj[v])
        if (u^p)
            dfs(u, v);
    out[v]=t++;
}

void upd(int i, db x) {
    for (++i; i<=n*2; i+=i&-i)
        bit[i]+=x;
}

db query(int i) {
    db ans=0;
    for (++i; i>0; i-=i&-i)
        ans+=bit[i];
    return ans;
}
db query(int l, int r) {
    return query(r)-query(l-1);
}

int main() {
    cout << setprecision(12) << fixed;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    cin >> q;
    while (q--) {
        int p, x, y;
        cin >> p >> x >> y;
        if (p==1) {
            upd(in[x], log(y)-a[in[x]]);
            a[in[x]]=log(y);
        }
        else {
            db c=query(in[x], out[x]), d=query(in[y], out[y]);
            if (c-d>=log(1e9))
                cout << 1e9 << '\n';
            else
                cout << exp(c-d) << '\n';
        }
    }
}

