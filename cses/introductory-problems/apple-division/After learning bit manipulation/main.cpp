#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=21;
ll n, tot, ans=INT_MAX, a[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i], tot+=a[i];
    for (int i=0; i<(1<<n); ++i) {
        ll cur=0;
        for (int j=0; j<n; ++j)
            if (i&(1<<j))
                cur+=a[j];
        ans=min(ans, abs(tot-2*cur));
    }
    cout << ans << '\n';
}

