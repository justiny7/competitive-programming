#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
int n, a[mxN], b[mxN];
ll ans, bit[mxN];

bool cmp(int x, int y) {
    return a[x]<a[y];
}
void upd(int i) {
    for (++i; i<mxN; i+=i&-i)
        ++bit[i];
}
ll query(int i) {
    ll ret=0;
    for (++i; i; i-=i&-i)
        ret+=bit[i];
    return ret;
}
ll query(int l, int r) {
    return query(r)-query(l-1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i], b[i]=i;
    sort(b, b+n, cmp);
    for (int i=0; i<n; ++i) {
        ans+=min(b[i]-query(0, b[i]), n-b[i]-1-query(b[i], n-1)); //Greedily choose left/right
        upd(b[i]);
    }
    cout << ans << '\n';
}

