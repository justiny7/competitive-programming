#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

const int mxN=10;
int n;
pii a[mxN*5];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    n=n*4+1;
    for (int i=0; i<n; ++i)
        cin >> a[i].fi >> a[i].se;
    for (int l=0; l<=50; ++l)
        for (int b=0; b<=50; ++b)
            for (int k=1; k<=50; ++k) {
                int u=b+k, r=l+k, cnt=0;
                if (u>50 || r>50)
                    break;
                pii ans;
                for (int i=0; i<n; ++i) {
                    if (((a[i].fi==l || a[i].fi==r) &&
                         (a[i].se<=u && a[i].se>=b)) ||
                        ((a[i].se==u || a[i].se==b) &&
                         (a[i].fi>=l && a[i].fi<=r)))
                        ++cnt;
                    else
                        ans=a[i];
                }
                if (cnt==n-1)
                    return cout << ans.fi << " " << ans.se << '\n', 0;
            }
}


