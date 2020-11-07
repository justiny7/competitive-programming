#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=2e3+1;
int n, root, c[mxN], a[mxN], cnt[mxN], bit[mxN];
vector<int> adj[mxN];

void upd(int i, int x) {
    for (; i<=n; i+=i&(-i))
        bit[i]+=x;
}

int query(int i) {
    int ans=0;
    for (; i>0; i-=i&(-i))
        ans+=bit[i];
    return ans;
}

int kth(int k) {
    ++k;
    int lo=1, hi=n;
    while (lo<hi) {
        int mid=(lo+hi)/2;
        if (query(mid)>=k)
            hi=mid;
        else
            lo=mid+1;
    }
    return lo;
}

void dfs(int v=root, int p=0) {
    int k=kth(c[v]);
    a[v]=k, upd(k, -1);
    cnt[v]=1;
    for (int u:adj[v])
        dfs(u, v), cnt[v]+=cnt[u];
    if (c[v]>cnt[v]-1) {
        cout << "NO\n";
        exit(0);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i) {
        int a;
        cin >> a >> c[i];
        if (a)
            adj[a].pb(i);
        else
            root=i;
        upd(i, 1);
    }
    dfs();
    cout << "YES\n";
    for (int i=1; i<=n; ++i)
        cout << a[i] << ((i^n)?" ":"\n");
}


