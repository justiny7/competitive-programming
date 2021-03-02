#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=5e3+1;
int n;
ll ans, a[mxN], save[mxN];

void solve() {
    ans=0;
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i], save[i]=0;
    for (int i=0; i<n; ++i) {
        ans+=max(0LL, a[i]-1-save[i]);
        save[i+1]+=max(save[i], a[i]-1)-a[i]+1;
        for (int j=i+2; j<=min(n-1, (int)(i+a[i])); ++j)
            ++save[j];
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

