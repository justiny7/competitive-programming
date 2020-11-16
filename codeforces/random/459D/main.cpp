#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e6+5;
int n, a[mxN];
ll bit[mxN], ans;
map<int, ll> mp, mp2;

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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        ++mp[a[i]];
    }
    for (int i=n-1; ~i; --i) {
        ans+=query(mp[a[i]]-1);
        --mp[a[i]], upd(++mp2[a[i]]);
    }
    cout << ans << '\n';
}

