#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int mxN=3e5+1;
ll n, p, ans, cnt[mxN];
map<pll, int> mp;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> p;
    for (int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        ++cnt[a], ++cnt[b], ++mp[pll(min(a, b), max(a, b))];
    }
    for (auto& x:mp) {
        ll s=cnt[x.fi.fi]+cnt[x.fi.se];
        if (s>=p)
            --ans;
        if (s-x.se>=p)
            ++ans;
    }
    sort(cnt+1, cnt+n+1);
    for (int i=1, j=n; i<=n; ++i) {
        while (j && cnt[j]+cnt[i]>=p)
            --j;
        ans+=n-max(i, j);
    }
    cout << ans << '\n';
}


