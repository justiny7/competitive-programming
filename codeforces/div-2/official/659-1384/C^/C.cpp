#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int mxN=1e5+1;
int n, par[21], sz[21];
string a, b;
pair<char, char> p[mxN];

int find(int v) {
    return (v==par[v]?v:par[v]=find(par[v]));
}

bool merge(int a, int b) {
    a=find(a), b=find(b);
    if (a^b) {
        if (sz[a]<sz[b])
            swap(a, b);
        par[b]=a, sz[a]+=sz[b];
        return 1;
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int ans=0;
        cin >> n >> a >> b;
        bool f=0;
        for (int i=0; i<n; ++i) {
            if (a[i]>b[i]) {
                f=1;
                break;
            }
            p[i].fi=a[i], p[i].se=b[i];
        }
        if (f) {
            cout << "-1\n";
            continue;
        }
        sort(p, p+n);
        for (int i=0; i<=20; ++i)
            sz[i]=1, par[i]=i;
        for (int i=0; i<n; ++i)
            if (merge(p[i].fi-'a', p[i].se-'a'))
                ++ans;
        cout << ans << '\n';
    }
}


