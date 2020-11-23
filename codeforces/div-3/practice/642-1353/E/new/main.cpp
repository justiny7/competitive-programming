#include <bits/stdc++.h>
using namespace std;

const int mxN=1e6+1;
int n, k, ans, pref[mxN], dp[mxN];
string s;

void go(int x) {
    fill(dp, dp+(n/k)+1, 0);
    for (int pos=x, i=0; pos<n; pos+=k, ++i) {
        if (pos==x)
            dp[i]=(s[pos]^'1')+pref[pos];
        else
            dp[i]=(s[pos]^'1')+min(dp[i-1]+pref[pos]-pref[pos-k+1], pref[pos]);
        ans=min(ans, dp[i]+pref[n]-pref[pos+1]);
    }
}
void solve() {
    cin >> n >> k >> s;
    fill(pref, pref+n+1, 0);
    for (int i=0; i<n; ++i)
        pref[i+1]=pref[i]+(s[i]=='1');
    ans=max(0, pref[n]-1);
    for (int i=0; i<k; ++i)
        go(i);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

