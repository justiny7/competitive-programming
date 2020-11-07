#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

int n;
pll a[200001];
ll cur, ans;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i].fi >> a[i].se;
    sort(a, a+n);
    for (int i=0; i<n; ++i)
        cur+=a[i].fi, ans+=a[i].se-cur;
    cout << ans << '\n';
}
