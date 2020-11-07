#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;
//Basic impl of Prim's was too slow so I took a hint at how to do it with Kruskal's w/ DSU
ifstream fin("fencedin.in");
ofstream fout("fencedin.out");

const int mxN=2e3+1, ky[]={1,0,-1,0}, kx[]={0,1,0,-1};
ll A, B, n, m, ans, sz[mxN*mxN], par[mxN*mxN];
vector<ll> a, b;

void make(ll v) {
    par[v]=v, sz[v]=1;
}

ll find(ll v) {
    if (v==par[v])
        return v;
    return par[v]=find(par[v]);
}

ll get(ll x, ll y) {
    return x*m+y;
}

bool combine(ll a, ll b) {
    a=find(a); b=find(b);
    if (a!=b) {
        if (sz[a]<sz[b])
            swap(a, b);
        par[b]=a, sz[a]+=sz[b];
        return 1;
    }
    return 0;
}

int main() {
    fin >> A >> B >> n >> m;
    a={0, A};
    for (int i=0; i<n; ++i) {
        int c; fin >> c;
        a.pb(c);
    }
    sort(a.begin(), a.end());
    b={0, B};
    for (int i=0; i<m; ++i) {
        int c; fin >> c;
        b.pb(c);
    }
    sort(b.begin(), b.end());
    n=a.size()-1, m=b.size()-1;
    for (int i=0; i<n; ++i)
        a[i]=a[i+1]-a[i];
    for (int i=0; i<m; ++i)
        b[i]=b[i+1]-b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll v=0, h=0;
    for (int i=0; i<n*m; ++i)
        make(i);
    while (v<n || h<m) {
        if (h==m || (v<n && a[v]<b[h])) {
            for (int i=0; i<m-1; ++i)
                if (combine(get(v, i), get(v, i+1)))
                    ans+=a[v];
            ++v;
        }
        else {
            for (int i=0; i<n-1; ++i)
                if (combine(get(i, h), get(i+1, h)))
                    ans+=b[h];
            ++h;
        }
    }
    fout << ans << '\n';
}
