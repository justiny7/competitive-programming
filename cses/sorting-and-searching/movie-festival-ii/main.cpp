#include <bits/stdc++.h>
#define fi first
#define se second
#define ub upper_bound
#define mp make_pair
using namespace std;
using pii=pair<int, int>;

const int mxN=2e5+1;
int n, k, ans;
pii t[mxN];
set<pii> s;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=0; i<n; ++i)
        cin >> t[i].se >> t[i].fi;
    sort(t, t+n);
    for (int i=0; i<k; ++i)
        s.insert({0, i});
    for (int i=0; i<n; ++i) {
        auto it=s.ub(mp(t[i].se, INT_MAX));
        if (it==s.begin())
            continue;
        ++ans, --it;
        s.insert(mp(t[i].fi, it->se));
        s.erase(it);
    }
    cout << ans << '\n';
}
