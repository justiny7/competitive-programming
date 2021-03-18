#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, ans=0;
    cin >> n >> m;
    map<int, int> mp;
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        ++mp[x%m];
    }
    if (mp[0])
        ++ans;
    for (int i=1; i*2<m; ++i)
        if (mp[i] || mp[m-i])
            ans+=max(1, abs(mp[i]-mp[m-i]));
    if (m%2==0 && mp[m/2])
        ++ans;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

