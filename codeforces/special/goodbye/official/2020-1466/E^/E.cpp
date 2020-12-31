#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll M=1e9+7;

void solve() {
    int n; cin >> n;
    vector<ll> a(n), cnt(61);
    for (ll &i:a)
        cin >> i;
    for (int i=0; i<n; ++i)
        for (int j=0; j<61; ++j)
            if (a[i]&(1LL<<j))
                ++cnt[j];
    ll ans=0;
    for (int i=0; i<n; ++i) {
        ll ors=0, ands=0;
        for (int j=0; j<61; ++j) {
            if (a[i]&(1LL<<j)) {
                (ands+=(1LL<<j)%M*cnt[j]%M)%=M;
                (ors+=(1LL<<j)%M*n%M)%=M;
            }
            else
                (ors+=(1LL<<j)%M*cnt[j]%M)%=M;
        }
        (ans+=(ands*ors)%M)%=M;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

