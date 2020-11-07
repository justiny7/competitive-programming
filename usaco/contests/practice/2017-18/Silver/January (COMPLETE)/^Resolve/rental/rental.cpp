#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int mxN=1e5+1;
ll n, m, r, c[mxN], rent[mxN], cur, ans;
pll buy[mxN];

int main() {
    ifstream cin("rental.in");
    ofstream cout("rental.out");
    cin >> n >> m >> r;
    for (int i=0; i<n; ++i)
        cin >> c[i];
    for (int i=0; i<m; ++i)
        cin >> buy[i].se >> buy[i].fi;
    for (int i=0; i<r; ++i)
        cin >> rent[i];
    sort(c, c+n, greater<ll>());
    sort(buy, buy+m, greater<pll>());
    sort(rent, rent+r);
    for (int i=0; i<min(n, r); ++i)
        cur+=rent[r-i-1];
    ans=cur;
    for (int i=0, j=0, k=r-min(n, r); i<n; ++i) {
        if (i>=n-r)
            cur-=rent[k++];
        while (j<m && c[i]) {
            if (c[i]<=buy[j].se)
                cur+=buy[j].fi*c[i], buy[j].se-=c[i], c[i]=0;
            else
                cur+=buy[j].se*buy[j].fi, c[i]-=buy[j].se, ++j;
        }
        ans=max(ans, cur);
    }
    cout << ans << '\n';
}

