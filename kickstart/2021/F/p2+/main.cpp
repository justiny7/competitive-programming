#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int d, n, k;
    cin >> d >> n >> k;

    map<int, vector<ll>> add, rem;
    while (n--) {
        int h, s, e;
        cin >> h >> s >> e;

        add[s].push_back(h);
        rem[e + 1].push_back(h);
    }

    ll sum = 0, ans = 0;
    multiset<ll> tp, bt;

    auto fix = [&]() {
        while (tp.size() && bt.size() && *bt.rbegin() > *tp.begin()) {
            sum += *bt.rbegin() - *tp.begin();
            int val = *bt.rbegin();
            bt.erase(bt.find(val));
            bt.insert(*tp.begin());
            tp.erase(tp.begin());
            tp.insert(val);
        }
    };
    auto ins = [&](int x) {
        if (tp.size() < k) {
            tp.insert(x);
            sum += x;
        } else {
            bt.insert(x);
            fix();
        }
    };
    auto del = [&](int x) {
        if (bt.find(x) != bt.end())
            bt.erase(bt.find(x));
        else {
            // cout << "finding " << x << '\n';
            assert(tp.find(x) != tp.end());
            sum -= x;
            tp.erase(tp.find(x));
            while (bt.size() && tp.size() < k) {
                int val = *bt.rbegin();
                sum += val;
                tp.insert(val);
                bt.erase(bt.find(val));
            }
            fix();
        }
    };

    for (int i = 1; i <= d; ++i) {
        for (ll x : add[i])
            ins(x);
        for (ll x : rem[i])
            del(x);

        /*
        cout << "hi:\n";
        for (int x : tp)
            cout << x << " ";
        cout << '\n';
        cout << "lo:\n";
        for (int x : bt)
            cout << x << " ";
        cout << '\n';
        */

        ans = max(ans, sum);
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

