#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 50;

void solve() {
    ll st, en, m;
    cin >> st >> en >> m;

    if (st == en) {
        cout << "1 " << st << '\n';
        return;
    }

    int n = -1;
    ll p = 0;
    for (int i = 2; __lg(p) + __lg(st + 1) <= __lg(en); ++i) {
        p = (1LL << (i - 2));
        //cout << "> " << i << " " << p << '\n';
        if (p * (st + 1) <= en && en <= p * (st + m)) {
            n = i;
            break;
        }
    }

    if (n < 0) {
        cout << "-1\n";
        return;
    }

    //cout << n << " " << p << '\n';

    ll d = 0;
    for (int i = __lg(m) + 1; ~i; --i)
        if (en - p * (st + (d | (1LL << i))) >= p)
            d |= (1LL << i);
    ++d;
    ll need = en - p * (st + d);

    //cout << d << " " << need << '\n';

    // a[n] = p * (st + d) + some r < p
    vector<ll> add(n);
    for (int i = 0; i < n - 1; ++i) {
        add[n - i - 1] = (need >> i & 1);
        //cout << i << " " << add[i] << '\n';
    }

    ll cur = 0, pref = st, c = 0;
    vector<ll> ans = {st};
    while (cur != en) {
        cur = pref + d;

        if (c < n - 2)
            cur += add[c + 2];

        ans.push_back(cur);
        pref += cur;
        ++c;
    }

    cout << ans.size();
    for (ll i : ans)
        cout << " " << i;
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--)
        solve();
}
