#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll cdiv(ll n, ll d) {
    return (n + d - 1) / d;
}

void solve() {
    ll R, C, k;
    ll r1, c1, r2, c2;

    cin >> R >> C >> k;
    cin >> r1 >> c1 >> r2 >> c2;

    ll len = c2 - c1 + 1, hgt = r2 - r1 + 1;
    
    ll verc = 2, horc = 2;
    if (r1 == 1)
        --horc;
    if (r2 == R)
        --horc;
    if (c1 == 1)
        --verc;
    if (c2 == C)
        --verc;

    ll ans = LLONG_MAX;
    { // north/south wall
        ll here = (verc == 2 ? cdiv(min(r2, R - r1 + 1), k) : 0); // inital cut
        cout << "here: " << here << '\n';

        { // split hor
            ll cur = here;
            cur += (len - 1 + (verc == 0 ? 0 : 1)) * cdiv(hgt, k); // add in vertical bars
            cout << cur << '\n';
            cur += (hgt - 1) * len; // add in horizontal singles
            cout << cur << '\n';
            cur += horc * cdiv(len, k);

            cout << cur << '\n';
            ans = min(ans, cur);
        }
        { // split ver
            ll cur = here;
            cur += (hgt - 1 + horc) * cdiv(len, k); // add in horizontal bars
            cur += (len - 1) * hgt; // add in vertical singles
            cur += (verc == 0 ? 0 : 1) * cdiv(hgt, k);

            cout << cur << '\n';
            ans = min(ans, cur);
        }
    }
    { // east/west wall
        ll here = (horc == 2 ? cdiv(min(c2, C - c1 + 1), k) : 0); // inital cut
        cout << "here: " << here << '\n';

        { // split hor
            ll cur = here;
            cur += (len - 1 + verc) * cdiv(hgt, k); // add in vertical bars
            cur += (hgt - 1) * len; // add in horizontal singles
            cur += (horc == 0 ? 0 : 1) * cdiv(len, k);

            cout << cur << '\n';
            ans = min(ans, cur);
        }
        { // split ver
            ll cur = here;
            cur += (hgt - 1 + (horc == 0 ? 0 : 1)) * cdiv(len, k); // add in horizontal bars
            cur += (len - 1) * hgt; // add in vertical singles
            cur += verc * cdiv(hgt, k);

            cout << cur << '\n';
            ans = min(ans, cur);
        }
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

