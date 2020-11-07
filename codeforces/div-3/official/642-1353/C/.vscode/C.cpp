#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int asdf = 0; asdf < t; asdf++) {
        ll n;
        cin >> n;

        ll ans = 0;
        ll sqcnt, movecnt = 0;
        for (ll i = 1; i <= n; i += 2) {
            if (i == 1)
                sqcnt = 1;
            else {
                sqcnt = i*i - (i-2)*(i-2);
            }
            //cout << "sqcnt:" << sqcnt << endl;
            ans += movecnt * sqcnt;
            movecnt++;
        }

        cout << ans << '\n';
    }

    return 0;
}