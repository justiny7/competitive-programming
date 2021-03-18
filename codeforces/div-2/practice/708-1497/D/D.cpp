#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=5e3+1;
int n, tag[mxN];
ll s[mxN], dp[mxN], cur[mxN];

void solve() {
    memset(dp, 0xc0, sizeof(dp));
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> tag[i];
    for (int i=0; i<n; ++i)
        cin >> s[i];
    for (int i=0; i<n; ++i) {
        memset(cur, 0xc0, sizeof(cur));
        cur[i]=0;
        for (int j=i-1; ~j; --j) {
            if (tag[i]==tag[j])
                continue;
            cur[j]=max(cur[j], cur[i]+abs(s[i]-s[j])); //i -> j
            cur[i]=max(cur[i], dp[j]+abs(s[i]-s[j])); //j -> i
        }
        for (int j=0; j<n; ++j)
            dp[j]=max(dp[j], cur[j]);
    }
    cout << *max_element(dp, dp+n) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

