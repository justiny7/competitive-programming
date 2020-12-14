#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1, M=1e9+7;
int ans, bit[mxN], a[mxN], b[mxN];

void upd(int i, int x) {
    for (; i<mxN; i+=i&-i)
        bit[i]=(bit[i]+x)%M;
}
int query(int i) {
    int ret=0;
    for (; i; i-=i&-i)
        ret=(ret+bit[i])%M;
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i], b[i]=a[i];
    sort(b, b+n);
    for (int i=0; i<n; ++i) {
        int x=lower_bound(b, b+n, a[i])-b+1,
            here=(1+query(x-1))%M;
        ans=(ans+here)%M, upd(x, here);
    }
    cout << ans << '\n';
}

