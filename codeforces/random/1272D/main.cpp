#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+5;
int n, a[mxN], dp_s[mxN], dp_e[mxN], ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    for (int i=1; i<=n; ++i)
        dp_e[i]=(a[i]>a[i-1]?dp_e[i-1]+1:1),
        ans=max(ans, dp_e[i]);
    for (int i=n; i; --i)
        dp_s[i]=(a[i]<a[i+1]?dp_s[i+1]+1:1);
    for (int i=2; i<n; ++i)
        if (a[i+1]>a[i-1])
            ans=max(ans, dp_e[i-1]+dp_s[i+1]);
    cout << ans << '\n';
}

