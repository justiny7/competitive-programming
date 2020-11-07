#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;
//Yay worked first try with no compiler errors and no debugging!
ifstream fin("bphoto.in");
ofstream fout("bphoto.out");

const int mxN=1e5+1;
int n, bit[mxN], ans;
pii a[mxN];

void add(int i) {
    for (++i; i<=n; i+=i&(-i))
        ++bit[i];
}

int query(int i) {
    int ans=0;
    for (++i; i>0; i-=i&(-i))
        ans+=bit[i];
    return ans;
}

int query(int l, int r) {
    return (query(r)-query(l-1));
}

int main() {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> a[i].fi, a[i].se=i;
    sort(a, a+n, greater<pii>());
    int i=0;
    while (i<n) {
        vector<pii> nxt={a[i++]};
        while (i<n && a[i].fi==a[i-1].fi)
            nxt.pb(a[i++]);
        for (auto& p:nxt) {
            int l=query(0, p.se),
                r=query(p.se, n-1);
            if (l>r)
                swap(l, r);
            if (l*2<r)
                ++ans;
        }
        for (auto& p:nxt)
            add(p.se);
    }
    fout << ans << '\n';
}

