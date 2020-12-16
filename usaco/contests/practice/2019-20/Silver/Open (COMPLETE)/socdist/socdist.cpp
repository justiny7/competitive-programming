//Yay worked first try
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int mxN=1e5+1;
int n, m;
pll a[mxN];

bool ok(ll x) {
    int c=0, cnt=1;
    ll pos=a[0].fi;
    while (c<m && cnt<n) {
        if (pos+x<=a[c].se)
            ++cnt, pos+=x;
        else {
            while (c<m && pos+x>a[c].se)
                ++c;
            if (c==m)
                break;
            ++cnt;
            if (pos+x<a[c].fi)
                pos=a[c].fi;
            else
                pos+=x;
        }
    }
    return (cnt==n);
}

int main() {
    ifstream cin("socdist.in");
    ofstream cout("socdist.out");
    cin >> n >> m;
    for (int i=0; i<m; ++i)
        cin >> a[i].fi >> a[i].se;
    sort(a, a+m);
    ll lo=1, hi=1e18;
    while (lo<hi) {
        ll m=lo+hi+1>>1;
        if (ok(m))
            lo=m;
        else
            hi=m-1;
    }
    cout << lo << '\n';
}

