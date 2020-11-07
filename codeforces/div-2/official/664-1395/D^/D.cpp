#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
ll n, d, m, a[mxN], pref[mxN], ans, tot;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> d >> m;
    for (int i=1; i<=n; ++i)
        cin >> a[i], tot+=a[i];
    sort(a+1, a+n+1);
    int ind=0;
    for (int i=1; i<=n; ++i) {
        pref[i]=pref[i-1]+a[i];
        if (a[i]<=m)
            ind=i;
    }
    for (int i=1, j=n; i<=n-ind && j>0; ++i, j-=d+1)
        ans=max(ans, tot+pref[ind]-pref[n-i]-(ind-j+1>0?pref[ind-j+1]:0));
    cout << (ans?ans:pref[ind]) << '\n';
}


