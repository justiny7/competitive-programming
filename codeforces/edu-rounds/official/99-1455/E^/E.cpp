#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

array<ll, 4> ox, oy;
array<pll, 4> sq;

void solve() {
    for (int i=0; i<4; ++i)
        cin >> ox[i] >> oy[i];
    {
        array<ll, 4> cx=ox, cy=oy;
        sort(cx.begin(), cx.end());
        sort(cy.begin(), cy.end());
        ll dif=max(cx[2]-cx[1], cy[2]-cy[1]),
           x=min(cx[1], cx[3]-dif),
           y=min(cy[1], cy[3]-dif);
        sq={pll(x, y), pll(x+dif, y), pll(x, y+dif), pll(x+dif, y+dif)};
    }
    vector<int> perm={0,1,2,3};
    ll ans=LLONG_MAX;
    do {
        ll cur=0;
        for (int i=0; i<4; ++i)
            cur+=abs(sq[i].first-ox[perm[i]])+abs(sq[i].second-oy[perm[i]]);
        ans=min(ans, cur);
    } while (next_permutation(perm.begin(), perm.end()));
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

