#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
int n, k, a[mxN];
ll ans=0;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    sort(a, a+n);
    ll cur=a[0];
    for (int i=1; i<n; ++i) {
        if (a[i]-a[i-1]<=k)
            cur+=a[i];
        else
            ans=max(ans, cur), cur=a[i];
    }
    cout << max(ans, cur) << '\n';
}

