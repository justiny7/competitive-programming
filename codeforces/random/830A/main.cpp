#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e3+1;
int n, k, p, a[mxN], b[mxN];
ll ans=LLONG_MAX;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> p;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=0; i<k; ++i)
        cin >> b[i];
    sort(a, a+n);
    sort(b, b+k);
    for (int i=0; i+n-1<k; ++i) {
        ll cur=0;
        for (int j=0; j<n; ++j)
            cur=max(cur, (ll)abs(a[j]-b[i+j])+abs(b[i+j]-p));
        ans=min(ans, cur);
    }
    cout << ans << '\n';
}

