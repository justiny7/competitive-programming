//Yay worked first try
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int, int>;

const int mxN=1e5+1;
int n, l, fr, br;
ll ans, bp, fp;
pii a[mxN];
vector<pii> v;

int main() {
    ifstream cin("reststops.in");
    ofstream cout("reststops.out");
    cin >> l >> n >> fr >> br;
    for (int i=0; i<n; ++i)
        cin >> a[i].fi >> a[i].se;
    sort(a, a+n);
    for (int i=n-1; ~i; --i)
        if (v.empty() || a[i].se>v.back().se)
            v.push_back(a[i]);
    for (int i=v.size()-1; ~i; --i) {
        ll cbt=(v[i].fi-bp)*br,
           cft=(v[i].fi-fp)*fr;
        ans+=(cft-cbt)*v[i].se;
        fp=bp=v[i].fi;
    }
    cout << ans << '\n';
}

