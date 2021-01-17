#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pi=pair<int, int>;

const int mxN=2e5+5;
int n, m, tot, par[mxN], cnt[mxN], ind[mxN];
map<int, int> s[mxN];

int find(int v) {
    return (v==par[v]?v:par[v]=find(par[v]));
}
bool merge(int a, int b) {
    a=find(a), b=find(b);
    if (a==b)
        return 0;
    int szb=cnt[b]+(s[b].size()-cnt[b])/2,
        sza=cnt[a]+(s[a].size()-cnt[a])/2;
    if (s[a].size()>s[b].size())
        swap(a, b);
    par[a]=b;
    for (pi p:s[a]) {
        if (p.se<p.fi)
            continue;
        int l=p.fi, r=p.se;
        if (s[b].count(r+1)) {
            if (s[b][r+1]==r+1)
                --cnt[b];
            r=s[b][r+1];
            s[b].erase(p.se+1);
        }
        if (s[b].count(l-1)) {
            if (s[b][l-1]==l-1)
                --cnt[b];
            l=s[b][l-1];
            s[b].erase(p.fi-1);
        }
        s[b][l]=r;
        s[b][r]=l;
        if (r==l)
            ++cnt[b];
    }
    s[a].clear();
    cnt[a]=0;
    tot-=szb+sza-(cnt[b]+(s[b].size()-cnt[b])/2);
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<=m; ++i)
        par[i]=i;
    for (int i=1; i<=n; ++i) {
        int x, l=i, r=i; cin >> x;
        if (s[x].count(r+1)) {
            if (s[x][r+1]==r+1)
                --cnt[x];
            r=s[x][r+1];
            s[x].erase(i+1);
        }
        if (s[x].count(l-1)) {
            if (s[x][l-1]==l-1)
                --cnt[x];
            l=s[x][l-1];
            s[x].erase(i-1);
        }
        s[x][l]=r;
        s[x][r]=l;
        if (l==r)
            ++cnt[x];
    }
    for (int i=1; i<=m; ++i) {
        ind[i]=i;
        tot+=cnt[i]+(s[i].size()-cnt[i])/2;
    }
    cout << tot-1 << '\n';
    for (int t=m-1; t--;) {
        int a, b;
        cin >> a >> b;
        merge(ind[a], ind[b]);
        ind[a]=ind[b];
        cout << tot-1 << '\n';
    }
}

