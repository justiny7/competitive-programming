#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;
using ll=long long;

int l, n, rb, rf;
ll ans;
pii stops[100001];

int main(void) {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    cin >> l >> n >> rf >> rb;
    for (int i=0; i<n; ++i)
        cin >> stops[i].se >> stops[i].fi;
    sort(stops, stops+n, greater<pii>());
    int cur=0;
    for (int i=0; i<n; ++i) {
        if (stops[i].se<cur)
            continue;
        int dif=stops[i].se-cur;
        ll tb=1LL*dif*rb, tf=1LL*dif*rf;
        ans+=1LL*(tf-tb)*stops[i].fi;
        cur=stops[i].se;
    }
    cout << ans << '\n';
}
